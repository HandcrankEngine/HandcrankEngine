#include <assert.h>

#include "Handcrank/Utilities.hpp"

int main()
{

    {
        assert(LeftPad("1", '0', 5).compare("00001") == 0);
        assert(RightPad("1", '0', 5).compare("10000") == 0);
    }

    return 0;
}
