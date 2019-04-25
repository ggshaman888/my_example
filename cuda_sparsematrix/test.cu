/* Copyright (c) 1993-2015, NVIDIA CORPORATION. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of NVIDIA CORPORATION nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "particle.h"
#include <stdlib.h>
#include <stdio.h>
# include <iostream>
# include <vector>
# include <fstream>
# include <numeric>
# include <cmath>
# include <chrono>
# include "sparsematrix.h"

const std::size_t Max_Iter = 50;

void print(const std::vector<double> &X);
std::vector<double> solve_SI(
    const SparseMatrix &A,
    double Epsilon);

std::vector<double> multiple(
    SparseMatrix &matrix,
    const std::vector<double> &vec);
double norm(const std::vector<double> &vec);
std::vector<double> plus(
    const std::vector<double> &first,
    const std::vector<double> &second);
std::vector<double> multiple(
    const std::vector<double> &vec,
    const double scalar);
void TransformMatrix(SparseMatrix &matrix);

//__global__ void advanceParticles(float dt, particle * pArray, int nParticles)
//{
//    int idx = threadIdx.x + blockIdx.x*blockDim.x; // number thread
//	if(idx < nParticles)
//	{
//		pArray[idx].advance(dt);
//	}
//}
__global__ void advanceParticles(particle * pArray, int nParticles, int nrows)
{
    int idx = threadIdx.x + blockIdx.x*blockDim.x; // number thread
    if(idx < nParticles)
    {

      //  pArray[idx].advance(dt);
        for(int j = 0; j < nrows; j++)
        {
            double x = pArray->matrixS.get(idx,j);
            double y = pArray->vecS[j];
            double r = pArray->Res[idx];
            double z = x*y;
            r = r+z;
            pArray->Res[idx] =r;
        }
    }
}
std::vector<double> multiple(
        SparseMatrix &matrix,
        const std::vector<double> &vec)
{
    std::vector<double> Res(0);
    cudaError_t error;
  //  int n = 1000000;
    int n = vec.size();
//    if(argc > 1)	{ n = atoi(argv[1]);}     // Number of particles
//    if(argc > 2)	{	srand(atoi(argv[2])); } // Random seed

    error = cudaGetLastError();
    if (error != cudaSuccess)
    {
    printf("0 %s\n",cudaGetErrorString(error));
    exit(1);
    }

    particle * pArray = new particle[0];
    pArray->multiple(matrix, vec);
    particle * devPArray = NULL;
    cudaMalloc(&devPArray, sizeof(pArray));
    cudaDeviceSynchronize(); error = cudaGetLastError();
    if (error != cudaSuccess)
    {
    printf("1 %s\n",cudaGetErrorString(error));
    exit(1);
    }

    cudaMemcpy(devPArray, pArray, sizeof(pArray), cudaMemcpyHostToDevice);
    cudaDeviceSynchronize(); error = cudaGetLastError();
    if (error != cudaSuccess)
    {
    printf("2 %s\n",cudaGetErrorString(error));
    exit(1);
    }
        int bufN = pArray->vecS.size();
        int buf_nrows = pArray->matrixS.m_nrows;
    //for(int i=0; i<100; i++)
    //{
//        float dt = (float)rand()/(float) RAND_MAX; // Random distance each step
        advanceParticles<<< 1 +  n/256, 256>>>(devPArray, bufN, buf_nrows);
        error = cudaGetLastError();
        if (error != cudaSuccess)
        {
        printf("3 %s\n",cudaGetErrorString(error));
        exit(1);
        }

        cudaDeviceSynchronize();
    //}
    cudaMemcpy(pArray, devPArray, sizeof(pArray), cudaMemcpyDeviceToHost);

//    v3 totalDistance(0,0,0);
//    v3 temp;
//    for(int i=0; i<n; i++)
//    {
//        temp = pArray[i].getTotalDistance();
//        totalDistance.x += temp.x;
//        totalDistance.y += temp.y;
//        totalDistance.z += temp.z;
//    }
//    float avgX = totalDistance.x /(float)n;
//    float avgY = totalDistance.y /(float)n;
//    float avgZ = totalDistance.z /(float)n;
//    float avgNorm = sqrt(avgX*avgX + avgY*avgY + avgZ*avgZ);
//    printf(	"Moved %d particles 100 steps. Average distance traveled is |(%f, %f, %f)| = %f\n",
//                    n, avgX, avgY, avgZ, avgNorm);


    return pArray->Res;
}
int main(int argc, char ** argv)
{
    auto matrix = SparseMatrix("a01.txt","b01.txt");
    auto start = std::chrono::steady_clock::now();
    auto X = solve_SI(matrix,1.0e-020);





    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout <<"Task takes "<< std::chrono::duration_cast<std::chrono::seconds>(diff).count() << " seconds\n";
    std::ofstream out("out_SI.txt");
    for(const auto &el : X)
        out<<el<<'\n';
    return 0;
}

//вычисление нормы
double norm(const std::vector<double> &vec)
{
    return sqrt(std::accumulate(vec.begin(),vec.end(),0.0,[](double x,double y)
    {
        return x+y*y;
    }));
}
//сложение векторов
std::vector<double> plus(
    const std::vector<double> &first,
    const std::vector<double> &second)
{
    std::vector<double> r(first.size(),0);
    std::transform(first.begin(),first.end(),second.begin(),r.begin(),[](const double &x,const double &y)
    {
        return x+y;
    });
    return r;
}
//умножение вектора на скаляр (поэлементное)
std::vector<double> multiple(
    const std::vector<double> &vec,
    const double scalar)
{
    std::vector<double> R(vec.size());
    std::transform(vec.begin(),vec.end(),R.begin(),[&scalar](const double &x)
    {
        return x*scalar;
    });
    return R;
}
//приведение матрицы к необходимому виду
void TransformMatrix(SparseMatrix &matrix)
{
    auto n = matrix.m_nrows;
    for(std::size_t i=0; i<n; i++)
    {
        auto el = matrix.get(i,i);
        if(el>0)
        {
            matrix.set(1-el,i,i);
            for(size_t j=0; j<n; j++)
                if(i!=j)
                    matrix.set(-matrix.get(i,j),i,j);
        }
        else
        {
            matrix.set(1+el,i,i);
            matrix.set(-matrix.get(i,n),i,n);
        }
    }
}
//реализация метода
std::vector<double> solve_SI(
    const SparseMatrix &A,
    double Epsilon)
{
    std::size_t iter=1;
    auto Matrix = A;
    auto n = Matrix.m_nrows;

    if(n == 0)
        return std::vector<double>{};

    auto B = Matrix.get_column(n);

    TransformMatrix(Matrix);
    std::cout << "start" << std::endl;
    auto X = std::vector<double>(n,0);
    while(iter<Max_Iter)
    {
        //делаем шаг
        auto Xnew = plus(multiple(Matrix,X),B);
        //расчитываем норму приращения(разница между 2-мя приближениями)
        double n2 = norm(plus(Xnew,multiple(X,-1)));

        if(n2<Epsilon)
        {
            std::cout<<"Количество итераций:"<<iter<<'\n';
            return X;
        }
        X = Xnew;
        ++iter;
    }
    std::cout<<"Метод расходится\n";
    return X;
}

void print(const std::vector<double> &X)
{
    for(const auto &el : X)
        std::cout<<el<<' ';
    std::cout<<'\n';
}
