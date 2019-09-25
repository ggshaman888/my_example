#ifndef API_FROM_UX_H
#define API_FROM_UX_H
#include <QString>
#include <QDateTime>
#include <QMetaType>

class APIFromUX {
public:
    explicit APIFromUX();
    APIFromUX(const APIFromUX&);
    enum MarkerIs { OTHER, SECOND };

    MarkerIs mark; ///<< Добавления маркера при передачи.

    void reset();
};
Q_DECLARE_METATYPE(APIFromUX)
#endif // API_FROM_UX_H
