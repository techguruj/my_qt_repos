#ifndef ENUMS_H
#define ENUMS_H

enum Tasten
{
    e_first = 1,
    e_prevoius = 2,
    e_next = 4,
    e_last = 8,
    e_new = 16,
    e_save = 32,
    e_cancel = 64
};                          //schalteButtons(Tasten::e_save+ Tasten::e_cancel)

enum TastenKombi
{
    edit = Tasten::e_save + Tasten::e_cancel,
    normal = Tasten::e_first + Tasten::e_prevoius + Tasten::e_next + Tasten::e_last + Tasten::e_new
};


enum Modus
{
    neutral,
    neu,
    update
};

#endif // ENUMS_H
