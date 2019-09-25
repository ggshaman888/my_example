#include "first.h"
#include "api_from_ux.h"

First::First(QObject* parent) : QObject(parent) {}

void First::runIs()
{
    auto api  = new APIFromUX;
    api->mark = APIFromUX::MarkerIs::OTHER;
    emit info(*api);
}
