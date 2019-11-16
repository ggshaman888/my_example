#include "read_tlv.h"

ReadTLV::ReadTLV() {}

void ReadTLV::readTLV(QString is_tlv)
{
    for (i = new ReadTLV::iter2(maxSizeTLV(is_tlv)); !i->isEnd(); i->iterUp()) {
        setTLV(is_tlv.mid(i->iterStr(), 2));
        if (!tlv_is_true) {
            break;
        }
    }
    if (tlv_is_true) {
        tlv_is_true = i->size();
    }
}

bool ReadTLV::tlvTrue()
{
    return tlv_is_true;
}

QList<ReadTLV::TLV_struct> ReadTLV::isTLV()
{
    return tlv;
}


int ReadTLV::maxSizeTLV(QString is_tlv)
{
    if (is_tlv.size() % 2 == 0) {
        return is_tlv.size() / 2;
    }
    else {
        return 0;
    }
}

uint8_t ReadTLV::fromHEX(QString is_hex)
{
    return static_cast<uint8_t>(is_hex.toLongLong(new bool, 16));
}

void ReadTLV::setTLV(QString is_byte)
{
    //! Обработка первого элемента.
    if (i->iterElem() == 0) {
        ndx_current_tag = 0;
        loadTag(fromHEX(is_byte));
        ndx_last_tag    = 3;
        tlv_element.tag = fromHEX(is_byte);
    }
    else {
        //! Проверяем на корректность расположения следующий TAG.
        if (ndx_last_tag == i->iterElem()) {
            if (loadTag(fromHEX(is_byte))) {
                //! Если дошли до следующего тега без проблем.
                tlv << tlv_element;
                current_tag     = last_tag;
                ndx_current_tag = i->iterElem();
                tlv_element.tag = fromHEX(is_byte);
                tlv_element.data.clear();
                tlv_element.length = 1;
                if (is_byte.count("FE")) {
                    ndx_last_tag = i->size();
                }
                else {
                    ndx_last_tag = i->iterElem() + 3;
                }
            }
            else {
                //! Ошибка, TLV не корректен.
                tlv_is_true = false;
            }
        }
        else {
            //! Считываем length.
            if (ndx_current_tag + 1 == i->iterElem()) {
                tlv_element.length = fromHEX(is_byte);
                //! пересчитываем данные следующего тега.
                ndx_last_tag = ndx_current_tag + 2 + tlv_element.length;
            }
            else {
                //! считываем data.
                tlv_element.data.append(is_byte);
            }
        }
    }
    //< Завершение парсинга.
    if (i->size() - 1 == i->iterElem()) {
        if (!tlv_element.data.isEmpty()) {
            tlv << tlv_element;
            tlv_element.tag = 0;
            tlv_element.data.clear();
            tlv_element.length = 1;
        }
    }
}

bool ReadTLV::loadTag(int is_tag)
{
    for (auto tag: tags) {
        if (tag == is_tag) {
            tlv_is_true = false;
        }
    }
    tags << is_tag;
    return tlv_is_true;
}

bool ReadTLV::iter2::isEnd()
{
    if (iter < size_is) {
        return false;
    }
    return true;
}

void ReadTLV::iter2::iterUp()
{
    iter++;
}

int ReadTLV::iter2::iterStr()
{
    return iter * 2;
}

int ReadTLV::iter2::iterElem()
{
    return iter;
}

int ReadTLV::iter2::size()
{
    return size_is;
}
