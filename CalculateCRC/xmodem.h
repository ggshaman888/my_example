#ifndef XMODEM_H
#define XMODEM_H

#include <QString>
/**
 * @brief The XMODEM class Calculate crc16 XModem. HEX to HEX mode.
 */
class XMODEM
{
public:
    XMODEM();
    void runCalculate();

private:
    const QString output = "123456789";

};

#endif // XMODEM_H
