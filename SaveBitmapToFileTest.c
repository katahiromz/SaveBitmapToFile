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
    static const INT array3[] =
    {
        1, 4, 8, 24, 32
    };
    HBITMAP hbm;
    BITMAP bm;
    size_t i, count;

    count = ARRAYSIZE(array1);
    for (i = 0; i < count; ++i)
    {
        hbm = LoadBitmapFromFile(array1[i]);
        assert(hbm != NULL);

        if (!GetObject(hbm, sizeof(bm), &bm))
            assert(0);

        assert(bm.bmBitsPixel == array3[i]);

        if (!SaveBitmapToFile(array2[i], hbm))
            assert(0);

        if (!DeleteObject(hbm))
            assert(0);
    }

    return 0;
}
