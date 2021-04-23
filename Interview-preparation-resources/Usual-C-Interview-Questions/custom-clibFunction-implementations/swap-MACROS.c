/************************ MACROS *********************************
******************************************************************/

#define SWAP_0(x,y) { x = x+y; \
                      y = x-y; \
                      x = x-y; }

//Faster than SWAP_0
#define SWAP_1(x,y) { x ^= y; \
                      y ^= x; \
                      x ^= y; }

//Optimal for general usage
#define SWAP_2(x,y)                                                                         \
                 do                                                                         \
                {                                                                           \
                    uint8_t __temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1];        \
                    memcpy(__temp,     &y, sizeof(x));                                      \
                    memcpy(    &y,     &x, sizeof(x));                                      \
                    memcpy(    &x, __temp, sizeof(x));                                      \
                } while(0)

//using GCC specific extension
#define SWAP_3(x, y) do                                                                     \
                    {                                                                       \
                        typeof(x) SWAP_3 = x; x = y; y = SWAP_3;                            \
                    }while (0)

//without GCC specific extension - can be invoked like this - SWAP_3(x,y, int) or SWAP_3(x,y, float)
#define SWAP_4(x, y, T) do                                                                  \
                    {                                                                       \
                        T SWAP_4 = x; x = y; y = SWAP_4;                                    \
                    }while (0)

