#include "SaveBitmapToFile.h"

#ifdef __cplusplus
    #include <cassert>
#else
    #include <assert.h>
#endif

int main(void)
{
    static const LPCTSTR array1[] =
    {
        TEXT("1bpp.bmp"),
        TEXT("4bpp.bmp"),
        TEXT("8bpp.bmp"),
        TEXT("24bpp.bmp"),
        TEXT("32bpp.bmp")
    };
    static const LPCTSTR array2[] =
    {
        TEXT("1bpp-saved.bmp"),
        TEXT("4bpp-saved.bmp"),
        TEXT("8bpp-saved.bmp"),
        TEXT("24bpp-saved.bmp"),
        TEXT("32bpp-saved.bmp")
    };
    size_t i, count = ARRAYSIZE(array1);
    for (size_t i = 0; i < count; ++i)
    {
        HBITMAP hbm = LoadBitmapFromFile(array1[i]);
        assert(hbm != NULL);

        if (!SaveBitmapToFile(array2[i], hbm))
            assert(0);

        if (!DeleteObject(hbm))
            assert(0);
    }

    return 0;
}
