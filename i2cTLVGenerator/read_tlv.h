#ifndef READTLV_H
#define READTLV_H

#include <QString>
#include <QList>
#include <QDebug>
/**
 * @brief The ReadTLV class Чтение TLV и оценка корректности.
 */
class ReadTLV {
public:
    ReadTLV();
    /**
     * @brief The TLV_struc struct Данные о поле в HEX формате
     */
    struct TLV_struct {
        TLV_struct() {}
        uint8_t tag; //< tag tlv.
        uint8_t length; //< Длина поля.
        QString data; //< Данные поля.
    };
    /**
    * @brief readTLV Прочитать готовый TLV в виде строки.
    */
    void readTLV(QString);
    /**
     * @brief tlvTrue Корректность TLV.
     * @return
     */
    bool tlvTrue();
    QList<TLV_struct> isTLV();

private:
    /**
     * @brief The iter2 class Для строки имитирующей HEX значения.
     */
    class iter2 {
    public:
        iter2(int max_size) : size_is(max_size) {}
        bool isEnd(); //< Элементы отсутствуют.
        void iterUp(); //< Увеличить итератор на 1.
        int iterStr(); //< Показать итератор для строки.
        int iterElem(); //< Показать итератор для элемента.
        int size(); //< Размер контейнера.
    private:
        int size_is = -1;
        int iter    = 0;
    };
    ReadTLV::iter2* i;
    /**
     * @brief maxSizeTLV Возвращает корректное количество TLV байт, или ноль.
     * @return
     */
    int maxSizeTLV(QString);
    QList<TLV_struct> tlv; //< TLV распарсенное.
    int current_tag; //< Содержимое текущего тега.
    int last_tag; //< Содержимое следующего тега.
    int ndx_current_tag; //< Индекс элемента в tlv для текущего тега.
    int ndx_last_tag; //< Индекс элемента в tlv для следующего тега.
    TLV_struct tlv_element; //< Один из элементов TLV структуры.
    uint8_t fromHEX(QString); //< Конвертировать HEX из строки в число.
    bool tlv_is_true = true;
    void setTLV(QString);
    QList<int> tags; //< обнаруженные TAG.
    bool loadTag(int); //< добавить в список новый TAG, если с таким именем нет.
};

#endif // READTLV_H
