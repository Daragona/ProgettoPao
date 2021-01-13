#ifndef MONOPATTINOELETTRICO_H
#define MONOPATTINOELETTRICO_H

#include "veicoloelettrico.h"
#include "monopattino.h"

class monopattinoElettrico: public monopattino, public veicoloElettrico
{
public:
    string accelleratore;
public:
    monopattinoElettrico(string a);

    string getAccelleratore() const;
};

#endif // MONOPATTINOELETTRICO_H
