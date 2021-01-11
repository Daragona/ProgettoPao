#ifndef MONOPATTINOELETTRICO_H
#define MONOPATTINOELETTRICO_H

#include "veicoloelettrico.h"
#include "monopattino.h"

class monopattinoElettrico: virtual public monopattino, virtual public veicoloElettrico
{
private:
    string accelleratore;
public:
    monopattinoElettrico(string a);

    string getAccelleratore() const;
};

#endif // MONOPATTINOELETTRICO_H
