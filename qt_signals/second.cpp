#include <QDebug>
#include "second.h"
#include "api_from_ux.h"

Second::Second(QObject* parent) : QObject(parent) {}

void Second::infoSlot(APIFromUX is_api)
{
    qDebug() << "__second";
    is_api.mark = APIFromUX::MarkerIs::SECOND;
    emit info(is_api);
}
