#include <QDebug>
#include "api_from_ux.h"

APIFromUX::APIFromUX()
{
    reset();
}

APIFromUX::APIFromUX(const APIFromUX& o) : mark(o.mark) {}

void APIFromUX::reset()
{
    this->mark = MarkerIs::OTHER;
}
