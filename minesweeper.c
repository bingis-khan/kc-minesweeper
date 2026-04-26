#include <stddef.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <stdint.h>
int _global_argc;
const char** _global_argv;
static  char   from_dash_charlike0 (    const char*  s49 ) {
    return ( * ( ( (char * ) (  s49 ) ) ) );
}

static  int64_t   from_dash_integral1 (    int64_t  x57 ) {
    return (  x57 );
}

static  int32_t   from_dash_integral2 (    int64_t  x60 ) {
    return ( (int32_t ) (  x60 ) );
}

static  uint32_t   from_dash_integral3 (    int64_t  x63 ) {
    return ( (uint32_t ) (  x63 ) );
}

static  uint16_t   from_dash_integral4 (    int64_t  x66 ) {
    return ( (uint16_t ) (  x66 ) );
}

static  uint8_t   from_dash_integral5 (    int64_t  x72 ) {
    return ( (uint8_t ) (  x72 ) );
}

static  uint64_t   from_dash_integral6 (    int64_t  x75 ) {
    return ( (uint64_t ) (  x75 ) );
}

static  size_t   from_dash_integral7 (    int64_t  x78 ) {
    return ( (size_t ) (  x78 ) );
}

static  bool   eq8 (    int32_t  l94 ,    int32_t  r96 ) {
    return ( (  l94 ) == (  r96 ) );
}

static  bool   eq9 (    uint32_t  l99 ,    uint32_t  r101 ) {
    return ( (  l99 ) == (  r101 ) );
}

static  bool   eq10 (    uint8_t  l104 ,    uint8_t  r106 ) {
    return ( (  l104 ) == (  r106 ) );
}

static  bool   eq11 (    uint16_t  l109 ,    uint16_t  r111 ) {
    return ( (  l109 ) == (  r111 ) );
}

static  bool   eq12 (    size_t  l114 ,    size_t  r116 ) {
    return ( (  l114 ) == (  r116 ) );
}

static  bool   eq13 (    char  l129 ,    char  r131 ) {
    return ( (  l129 ) == (  r131 ) );
}

enum Color8_17 {
    Color8_17_Black8,
    Color8_17_Red8,
    Color8_17_Green8,
    Color8_17_Yellow8,
    Color8_17_Blue8,
    Color8_17_Magenta8,
    Color8_17_Cyan8,
    Color8_17_White8,
};

enum Color16_18 {
    Color16_18_Black16,
    Color16_18_Red16,
    Color16_18_Green16,
    Color16_18_Yellow16,
    Color16_18_Blue16,
    Color16_18_Magenta16,
    Color16_18_Cyan16,
    Color16_18_White16,
    Color16_18_BrightBlack16,
    Color16_18_BrightRed16,
    Color16_18_BrightGreen16,
    Color16_18_BrightYellow16,
    Color16_18_BrightBlue16,
    Color16_18_BrightMagenta16,
    Color16_18_BrightCyan16,
    Color16_18_BrightWhite16,
};

struct RGB_19 {
    uint8_t  f_r;
    uint8_t  f_g;
    uint8_t  f_b;
};

struct Color_16 {
    enum {
        Color_16_ColorDefault_t,
        Color_16_Color8_t,
        Color_16_Color16_t,
        Color_16_Color256_t,
        Color_16_ColorRGB_t,
    } tag;
    union {
        struct {
            enum Color8_17  field0;
        } Color_16_Color8_s;
        struct {
            enum Color16_18  field0;
        } Color_16_Color16_s;
        struct {
            uint8_t  field0;
        } Color_16_Color256_s;
        struct {
            struct RGB_19  field0;
        } Color_16_ColorRGB_s;
    } stuff;
};

static struct Color_16 Color_16_Color8 (  enum Color8_17  field0 ) {
    return ( struct Color_16 ) { .tag = Color_16_Color8_t, .stuff = { .Color_16_Color8_s = { .field0 = field0 } } };
};

static struct Color_16 Color_16_Color16 (  enum Color16_18  field0 ) {
    return ( struct Color_16 ) { .tag = Color_16_Color16_t, .stuff = { .Color_16_Color16_s = { .field0 = field0 } } };
};

static struct Color_16 Color_16_Color256 (  uint8_t  field0 ) {
    return ( struct Color_16 ) { .tag = Color_16_Color256_t, .stuff = { .Color_16_Color256_s = { .field0 = field0 } } };
};

static struct Color_16 Color_16_ColorRGB (  struct RGB_19  field0 ) {
    return ( struct Color_16 ) { .tag = Color_16_ColorRGB_t, .stuff = { .Color_16_ColorRGB_s = { .field0 = field0 } } };
};

struct Cell_15 {
    char  f_c;
    struct Color_16  f_fg;
    struct Color_16  f_bg;
};

struct Tuple2_22 {
    struct Color_16  field0;
    struct Color_16  field1;
};

static struct Tuple2_22 Tuple2_22_Tuple2 (  struct Color_16  field0 ,  struct Color_16  field1 ) {
    return ( struct Tuple2_22 ) { .field0 = field0 ,  .field1 = field1 };
};

static  void *   cast_dash_ptr28 (    int32_t *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  size_t   size_dash_of29 (    int32_t  x479 ) {
    return ( sizeof( (  x479 ) ) );
}

static  int32_t   zeroed26 (  ) {
    int32_t  temp27;
    int32_t  x495 = (  temp27 );
    ( ( memset ) ( ( (  cast_dash_ptr28 ) ( ( & (  x495 ) ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_of29 ) ( (  x495 ) ) ) ) );
    return (  x495 );
}

static  enum Color8_17 *   cast30 (    int32_t *  x485 ) {
    return ( (enum Color8_17 * ) (  x485 ) );
}

static  int32_t   cast_dash_on_dash_zeroed24 (    enum Color8_17  x498 ) {
    int32_t  temp25 = ( (  zeroed26 ) ( ) );
    int32_t *  y499 = ( &temp25 );
    enum Color8_17 *  yp500 = ( (  cast30 ) ( (  y499 ) ) );
    (*  yp500 ) = (  x498 );
    return ( * (  y499 ) );
}

static  bool   eq23 (    enum Color8_17  l2046 ,    enum Color8_17  r2048 ) {
    return (  eq8 ( ( ( (  cast_dash_on_dash_zeroed24 ) ( (  l2046 ) ) ) ) , ( (  cast_dash_on_dash_zeroed24 ) ( (  r2048 ) ) ) ) );
}

static  enum Color16_18 *   cast34 (    int32_t *  x485 ) {
    return ( (enum Color16_18 * ) (  x485 ) );
}

static  int32_t   cast_dash_on_dash_zeroed32 (    enum Color16_18  x498 ) {
    int32_t  temp33 = ( (  zeroed26 ) ( ) );
    int32_t *  y499 = ( &temp33 );
    enum Color16_18 *  yp500 = ( (  cast34 ) ( (  y499 ) ) );
    (*  yp500 ) = (  x498 );
    return ( * (  y499 ) );
}

static  bool   eq31 (    enum Color16_18  l2052 ,    enum Color16_18  r2054 ) {
    return (  eq8 ( ( ( (  cast_dash_on_dash_zeroed32 ) ( (  l2052 ) ) ) ) , ( (  cast_dash_on_dash_zeroed32 ) ( (  r2054 ) ) ) ) );
}

static  bool   eq35 (    struct RGB_19  l2082 ,    struct RGB_19  r2084 ) {
    return ( ( (  eq10 ( ( (  l2082 ) .f_r ) , ( (  r2084 ) .f_r ) ) ) && (  eq10 ( ( (  l2082 ) .f_g ) , ( (  r2084 ) .f_g ) ) ) ) && (  eq10 ( ( (  l2082 ) .f_b ) , ( (  r2084 ) .f_b ) ) ) );
}

static  bool   eq21 (    struct Color_16  l2105 ,    struct Color_16  r2107 ) {
    return ( {  struct Tuple2_22  dref2108 = ( ( Tuple2_22_Tuple2 ) ( (  l2105 ) ,  (  r2107 ) ) ) ; dref2108 .field0.tag == Color_16_ColorDefault_t && dref2108 .field1.tag == Color_16_ColorDefault_t ? ( true ) : dref2108 .field0.tag == Color_16_Color8_t && dref2108 .field1.tag == Color_16_Color8_t ? (  eq23 ( ( dref2108 .field0 .stuff .Color_16_Color8_s .field0 ) , ( dref2108 .field1 .stuff .Color_16_Color8_s .field0 ) ) ) : dref2108 .field0.tag == Color_16_Color16_t && dref2108 .field1.tag == Color_16_Color16_t ? (  eq31 ( ( dref2108 .field0 .stuff .Color_16_Color16_s .field0 ) , ( dref2108 .field1 .stuff .Color_16_Color16_s .field0 ) ) ) : dref2108 .field0.tag == Color_16_Color256_t && dref2108 .field1.tag == Color_16_Color256_t ? (  eq10 ( ( dref2108 .field0 .stuff .Color_16_Color256_s .field0 ) , ( dref2108 .field1 .stuff .Color_16_Color256_s .field0 ) ) ) : dref2108 .field0.tag == Color_16_ColorRGB_t && dref2108 .field1.tag == Color_16_ColorRGB_t ? (  eq35 ( ( dref2108 .field0 .stuff .Color_16_ColorRGB_s .field0 ) , ( dref2108 .field1 .stuff .Color_16_ColorRGB_s .field0 ) ) ) : ( false ) ; } );
}

static  bool   eq20 (    struct Cell_15  l2755 ,    struct Cell_15  r2757 ) {
    if ( ( !  eq13 ( ( (  l2755 ) .f_c ) , ( (  r2757 ) .f_c ) ) ) ) {
        return ( false );
    }
    if ( ( !  eq21 ( ( (  l2755 ) .f_fg ) , ( (  r2757 ) .f_fg ) ) ) ) {
        return ( false );
    }
    if ( ( !  eq21 ( ( (  l2755 ) .f_bg ) , ( (  r2757 ) .f_bg ) ) ) ) {
        return ( false );
    }
    return ( true );
}

static  bool   eq14 (    struct Cell_15 *  dref141 ,    struct Cell_15 *  dref143 ) {
    return (  eq20 ( ( (* dref141 ) ) , ( (* dref143 ) ) ) );
}

enum Ordering_37 {
    Ordering_37_LT,
    Ordering_37_EQ,
    Ordering_37_GT,
};

static int64_t builtin_int64_tcmp (int64_t l, int64_t r) {
    return (l < r) ? 0 : (l == r) ? 1 : 2;
}

static  enum Ordering_37   cmp36 (    int64_t  l147 ,    int64_t  r149 ) {
    return ( builtin_int64_tcmp( (  l147 ) , (  r149 ) ) );
}

static size_t builtin_size_tcmp (size_t l, size_t r) {
    return (l < r) ? 0 : (l == r) ? 1 : 2;
}

static  enum Ordering_37   cmp38 (    size_t  l152 ,    size_t  r154 ) {
    return ( builtin_size_tcmp( (  l152 ) , (  r154 ) ) );
}

static int32_t builtin_int32_tcmp (int32_t l, int32_t r) {
    return (l < r) ? 0 : (l == r) ? 1 : 2;
}

static  enum Ordering_37   cmp39 (    int32_t  l157 ,    int32_t  r159 ) {
    return ( builtin_int32_tcmp( (  l157 ) , (  r159 ) ) );
}

static uint32_t builtin_uint32_tcmp (uint32_t l, uint32_t r) {
    return (l < r) ? 0 : (l == r) ? 1 : 2;
}

static  enum Ordering_37   cmp40 (    uint32_t  l162 ,    uint32_t  r164 ) {
    return ( builtin_uint32_tcmp( (  l162 ) , (  r164 ) ) );
}

static uint8_t builtin_uint8_tcmp (uint8_t l, uint8_t r) {
    return (l < r) ? 0 : (l == r) ? 1 : 2;
}

static  enum Ordering_37   cmp41 (    uint8_t  l167 ,    uint8_t  r169 ) {
    return ( builtin_uint8_tcmp( (  l167 ) , (  r169 ) ) );
}

static  int64_t   op_dash_add42 (    int64_t  l177 ,    int64_t  r179 ) {
    return ( (  l177 ) + (  r179 ) );
}

static  int64_t   op_dash_sub43 (    int64_t  l182 ,    int64_t  r184 ) {
    return ( (  l182 ) - (  r184 ) );
}

static  int64_t   op_dash_mul44 (    int64_t  l187 ,    int64_t  r189 ) {
    return ( (  l187 ) * (  r189 ) );
}

static  int64_t   op_dash_div45 (    int64_t  l192 ,    int64_t  r194 ) {
    return ( (  l192 ) / (  r194 ) );
}

static  int32_t   op_dash_add46 (    int32_t  l200 ,    int32_t  r202 ) {
    return ( (  l200 ) + (  r202 ) );
}

static  int32_t   op_dash_sub47 (    int32_t  l205 ,    int32_t  r207 ) {
    return ( (  l205 ) - (  r207 ) );
}

static  int32_t   op_dash_mul48 (    int32_t  l210 ,    int32_t  r212 ) {
    return ( (  l210 ) * (  r212 ) );
}

static  int32_t   op_dash_div49 (    int32_t  l215 ,    int32_t  r217 ) {
    return ( (  l215 ) / (  r217 ) );
}

static  int32_t   op_dash_neg50 (    int32_t  x220 ) {
    return ( (  from_dash_integral2 ( 0 ) ) - (  x220 ) );
}

static  uint32_t   op_dash_add51 (    uint32_t  l223 ,    uint32_t  r225 ) {
    return ( (  l223 ) + (  r225 ) );
}

static  uint32_t   op_dash_sub52 (    uint32_t  l228 ,    uint32_t  r230 ) {
    return ( (  l228 ) - (  r230 ) );
}

static  uint32_t   op_dash_mul53 (    uint32_t  l233 ,    uint32_t  r235 ) {
    return ( (  l233 ) * (  r235 ) );
}

static  uint32_t   op_dash_div54 (    uint32_t  l238 ,    uint32_t  r240 ) {
    return ( (  l238 ) / (  r240 ) );
}

static  uint8_t   op_dash_add55 (    uint8_t  l243 ,    uint8_t  r245 ) {
    return ( (  l243 ) + (  r245 ) );
}

static  uint8_t   op_dash_sub56 (    uint8_t  l248 ,    uint8_t  r250 ) {
    return ( (  l248 ) - (  r250 ) );
}

static  size_t   op_dash_add57 (    size_t  l263 ,    size_t  r265 ) {
    return ( (  l263 ) + (  r265 ) );
}

static  size_t   op_dash_sub58 (    size_t  l268 ,    size_t  r270 ) {
    return ( (  l268 ) - (  r270 ) );
}

static  size_t   op_dash_mul59 (    size_t  l273 ,    size_t  r275 ) {
    return ( (  l273 ) * (  r275 ) );
}

struct Array_62 {
    uint32_t _arr [4];
};

struct SmolArray_61 {
    struct Array_62  f_arr;
};

static  struct SmolArray_61   from_dash_listlike60 (    struct Array_62  arr307 ) {
    return ( (struct SmolArray_61) { .f_arr = (  arr307 ) } );
}

struct Array_65 {
    uint32_t _arr [5];
};

struct SmolArray_64 {
    struct Array_65  f_arr;
};

static  struct SmolArray_64   from_dash_listlike63 (    struct Array_65  arr307 ) {
    return ( (struct SmolArray_64) { .f_arr = (  arr307 ) } );
}

struct Array_68 {
    uint32_t _arr [1];
};

struct SmolArray_67 {
    struct Array_68  f_arr;
};

static  struct SmolArray_67   from_dash_listlike66 (    struct Array_68  arr307 ) {
    return ( (struct SmolArray_67) { .f_arr = (  arr307 ) } );
}

static  int32_t   clock_dash_monotonic69 (  ) {
    return (  from_dash_integral2 ( 1 ) );
}

static  int32_t   stdout_dash_fileno70 (  ) {
    return (  from_dash_integral2 ( 1 ) );
}

static  int32_t   stdin_dash_fileno71 (  ) {
    return (  from_dash_integral2 ( 0 ) );
}

static  uint32_t   echo72 (  ) {
    return (  from_dash_integral3 ( 8 ) );
}

static  uint32_t   icanon73 (  ) {
    return (  from_dash_integral3 ( 2 ) );
}

static  uint32_t   isig74 (  ) {
    return (  from_dash_integral3 ( 1 ) );
}

static  uint32_t   iexten75 (  ) {
    return (  from_dash_integral3 ( 32768 ) );
}

static  uint32_t   brkint76 (  ) {
    return (  from_dash_integral3 ( 2 ) );
}

static  uint32_t   icrnl77 (  ) {
    return (  from_dash_integral3 ( 256 ) );
}

static  uint32_t   inpck78 (  ) {
    return (  from_dash_integral3 ( 16 ) );
}

static  uint32_t   istrip79 (  ) {
    return (  from_dash_integral3 ( 32 ) );
}

static  uint32_t   ixon80 (  ) {
    return (  from_dash_integral3 ( 1024 ) );
}

static  uint32_t   opost81 (  ) {
    return (  from_dash_integral3 ( 1 ) );
}

static  uint32_t   cs882 (  ) {
    return (  from_dash_integral3 ( 48 ) );
}

static  size_t   vmin83 (  ) {
    return (  from_dash_integral7 ( 6 ) );
}

static  size_t   vtime84 (  ) {
    return (  from_dash_integral7 ( 5 ) );
}

static  int32_t   tcsa_dash_flush85 (  ) {
    return (  from_dash_integral2 ( 2 ) );
}

static  uint64_t   tiocgwinsz86 (  ) {
    return (  from_dash_integral6 ( 21523 ) );
}

static  int64_t   undefined87 (  ) {
    int64_t  temp88;
    return (  temp88 );
}

struct Tile_91 {
    bool  f_hidden;
    bool  f_is_dash_bomb;
    bool  f_flagged;
};

struct Slice_90 {
    struct Tile_91 *  f_ptr;
    size_t  f_count;
};

static  struct Slice_90   undefined89 (  ) {
    struct Slice_90  temp92;
    return (  temp92 );
}

static  struct Tile_91   undefined93 (  ) {
    struct Tile_91  temp94;
    return (  temp94 );
}

struct Array_97 {
    uint8_t _arr [32];
};

struct Termios_96 {
    uint32_t  f_c_dash_iflag;
    uint32_t  f_c_dash_oflag;
    uint32_t  f_c_dash_cflag;
    uint32_t  f_c_dash_lflag;
    uint8_t  f_c_dash_line;
    struct Array_97  f_c_dash_cc;
    uint32_t  f_c_dash_ispeed;
    uint32_t  f_c_dash_ospeed;
};

static  struct Termios_96   undefined95 (  ) {
    struct Termios_96  temp98;
    return (  temp98 );
}

static  struct timespec   undefined99 (  ) {
    struct timespec  temp100;
    return (  temp100 );
}

static  struct Cell_15   undefined101 (  ) {
    struct Cell_15  temp102;
    return (  temp102 );
}

static  char   undefined103 (  ) {
    char  temp104;
    return (  temp104 );
}

enum MouseButton_106 {
    MouseButton_106_MouseLeft,
    MouseButton_106_MouseMiddle,
    MouseButton_106_MouseRight,
    MouseButton_106_ScrollUp,
    MouseButton_106_ScrollDown,
};

static  enum MouseButton_106   undefined105 (  ) {
    enum MouseButton_106  temp107;
    return (  temp107 );
}

static  uint8_t   undefined108 (  ) {
    uint8_t  temp109;
    return (  temp109 );
}

static  struct Cell_15 *   undefined110 (  ) {
    struct Cell_15 *  temp111;
    return (  temp111 );
}

static  const char* *   offset_dash_ptr112 (    const char* *  x472 ,    int64_t  count474 ) {
    const char*  temp113;
    return ( (const char* * ) ( ( (void*) (  x472 ) ) + (  op_dash_mul44 ( (  count474 ) , ( (int64_t ) ( sizeof( ( (  temp113 ) ) ) ) ) ) ) ) );
}

static  char *   offset_dash_ptr114 (    char *  x472 ,    int64_t  count474 ) {
    char  temp115;
    return ( (char * ) ( ( (void*) (  x472 ) ) + (  op_dash_mul44 ( (  count474 ) , ( (int64_t ) ( sizeof( ( (  temp115 ) ) ) ) ) ) ) ) );
}

static  struct Slice_90 *   offset_dash_ptr116 (    struct Slice_90 *  x472 ,    int64_t  count474 ) {
    struct Slice_90  temp117;
    return ( (struct Slice_90 * ) ( ( (void*) (  x472 ) ) + (  op_dash_mul44 ( (  count474 ) , ( (int64_t ) ( sizeof( ( (  temp117 ) ) ) ) ) ) ) ) );
}

static  struct Tile_91 *   offset_dash_ptr118 (    struct Tile_91 *  x472 ,    int64_t  count474 ) {
    struct Tile_91  temp119;
    return ( (struct Tile_91 * ) ( ( (void*) (  x472 ) ) + (  op_dash_mul44 ( (  count474 ) , ( (int64_t ) ( sizeof( ( (  temp119 ) ) ) ) ) ) ) ) );
}

static  uint8_t *   offset_dash_ptr120 (    uint8_t *  x472 ,    int64_t  count474 ) {
    uint8_t  temp121;
    return ( (uint8_t * ) ( ( (void*) (  x472 ) ) + (  op_dash_mul44 ( (  count474 ) , ( (int64_t ) ( sizeof( ( (  temp121 ) ) ) ) ) ) ) ) );
}

static  uint32_t *   offset_dash_ptr122 (    uint32_t *  x472 ,    int64_t  count474 ) {
    uint32_t  temp123;
    return ( (uint32_t * ) ( ( (void*) (  x472 ) ) + (  op_dash_mul44 ( (  count474 ) , ( (int64_t ) ( sizeof( ( (  temp123 ) ) ) ) ) ) ) ) );
}

static  struct Cell_15 *   offset_dash_ptr124 (    struct Cell_15 *  x472 ,    int64_t  count474 ) {
    struct Cell_15  temp125;
    return ( (struct Cell_15 * ) ( ( (void*) (  x472 ) ) + (  op_dash_mul44 ( (  count474 ) , ( (int64_t ) ( sizeof( ( (  temp125 ) ) ) ) ) ) ) ) );
}

struct TypeSize_127 {
    size_t  f_size;
};

static  struct TypeSize_127   get_dash_typesize126 (  ) {
    struct Slice_90  temp128;
    return ( (struct TypeSize_127) { .f_size = ( sizeof( ( (  temp128 ) ) ) ) } );
}

struct TypeSize_130 {
    size_t  f_size;
};

static  struct TypeSize_130   get_dash_typesize129 (  ) {
    struct Tile_91  temp131;
    return ( (struct TypeSize_130) { .f_size = ( sizeof( ( (  temp131 ) ) ) ) } );
}

struct TypeSize_133 {
    size_t  f_size;
};

static  struct TypeSize_133   get_dash_typesize132 (  ) {
    struct Cell_15  temp134;
    return ( (struct TypeSize_133) { .f_size = ( sizeof( ( (  temp134 ) ) ) ) } );
}

static  size_t   size_dash_of135 (    void *  x479 ) {
    return ( sizeof( (  x479 ) ) );
}

static  size_t   size_dash_of136 (    uint32_t  x479 ) {
    return ( sizeof( (  x479 ) ) );
}

struct Winsize_138 {
    uint16_t  f_ws_dash_row;
    uint16_t  f_ws_dash_col;
    uint16_t  f_ws_dash_xpixel;
    uint16_t  f_ws_dash_ypixel;
};

static  size_t   size_dash_of137 (    struct Winsize_138  x479 ) {
    return ( sizeof( (  x479 ) ) );
}

static  size_t   size_dash_of139 (    FILE *  x479 ) {
    return ( sizeof( (  x479 ) ) );
}

enum Unit_141 {
    Unit_141_Unit,
};

static  size_t   size_dash_of140 (    enum Unit_141 *  x479 ) {
    return ( sizeof( (  x479 ) ) );
}

static  size_t   size_dash_of142 (    size_t  x479 ) {
    return ( sizeof( (  x479 ) ) );
}

static  size_t   size_dash_of143 (    char  x479 ) {
    return ( sizeof( (  x479 ) ) );
}

struct Array_145 {
    char _arr [32];
};

static  size_t   size_dash_of144 (    struct Array_145  x479 ) {
    return ( sizeof( (  x479 ) ) );
}

static  size_t   size_dash_of146 (    int64_t  x479 ) {
    return ( sizeof( (  x479 ) ) );
}

static  size_t   size_dash_of147 (    struct timespec *  x479 ) {
    return ( sizeof( (  x479 ) ) );
}

static  uint32_t   cast148 (    int32_t  x485 ) {
    return ( (uint32_t ) (  x485 ) );
}

static  char *   cast149 (    int32_t *  x485 ) {
    return ( (char * ) (  x485 ) );
}

static  char *   cast150 (    const char*  x485 ) {
    return ( (char * ) (  x485 ) );
}

static  int32_t   cast151 (    uint32_t  x485 ) {
    return ( (int32_t ) (  x485 ) );
}

static  uint16_t *   cast152 (    uint32_t *  x485 ) {
    return ( (uint16_t * ) (  x485 ) );
}

static  enum Unit_141 *   cast153 (    const char*  x485 ) {
    return ( (enum Unit_141 * ) (  x485 ) );
}

static  uint32_t *   cast154 (    size_t *  x485 ) {
    return ( (uint32_t * ) (  x485 ) );
}

static  uint8_t   cast155 (    char  x485 ) {
    return ( (uint8_t ) (  x485 ) );
}

static  uint8_t *   cast156 (    int64_t *  x485 ) {
    return ( (uint8_t * ) (  x485 ) );
}

static  char   cast157 (    int32_t  x485 ) {
    return ( (char ) (  x485 ) );
}

static  char *   cast158 (    struct Array_145 *  x485 ) {
    return ( (char * ) (  x485 ) );
}

static  enum MouseButton_106 *   cast159 (    uint32_t *  x485 ) {
    return ( (enum MouseButton_106 * ) (  x485 ) );
}

static  uint8_t *   cast160 (    int32_t *  x485 ) {
    return ( (uint8_t * ) (  x485 ) );
}

static  void *   cast_dash_ptr161 (    void * *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  struct Slice_90 *   cast_dash_ptr162 (    void *  p488 ) {
    return ( (struct Slice_90 * ) (  p488 ) );
}

static  struct Tile_91 *   cast_dash_ptr163 (    void *  p488 ) {
    return ( (struct Tile_91 * ) (  p488 ) );
}

static  void *   cast_dash_ptr164 (    uint32_t *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  void *   cast_dash_ptr165 (    struct Winsize_138 *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  uint8_t *   cast_dash_ptr166 (    struct Array_97 *  p488 ) {
    return ( (uint8_t * ) (  p488 ) );
}

static  struct termios *   cast_dash_ptr167 (    struct Termios_96 *  p488 ) {
    return ( (struct termios * ) (  p488 ) );
}

static  uint32_t *   cast_dash_ptr168 (    struct Array_62 *  p488 ) {
    return ( (uint32_t * ) (  p488 ) );
}

static  uint32_t *   cast_dash_ptr169 (    struct Array_65 *  p488 ) {
    return ( (uint32_t * ) (  p488 ) );
}

static  uint32_t *   cast_dash_ptr170 (    struct Array_68 *  p488 ) {
    return ( (uint32_t * ) (  p488 ) );
}

static  void *   cast_dash_ptr171 (    FILE * *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  void *   cast_dash_ptr172 (    enum Unit_141 * *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  void *   cast_dash_ptr173 (    size_t *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  struct Cell_15 *   cast_dash_ptr174 (    void *  p488 ) {
    return ( (struct Cell_15 * ) (  p488 ) );
}

struct Pollfd_176 {
    int32_t  f_fd;
    uint16_t  f_events;
    uint16_t  f_revents;
};

static  struct pollfd *   cast_dash_ptr175 (    struct Pollfd_176 *  p488 ) {
    return ( (struct pollfd * ) (  p488 ) );
}

static  void *   cast_dash_ptr177 (    char *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  char *   cast_dash_ptr178 (    struct Array_145 *  p488 ) {
    return ( (char * ) (  p488 ) );
}

static  void *   cast_dash_ptr179 (    struct Array_145 *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  void *   cast_dash_ptr180 (    int64_t *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  void *   cast_dash_ptr181 (    struct timespec * *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  void *   cast_dash_ptr182 (    struct Cell_15 *  p488 ) {
    return ( (void * ) (  p488 ) );
}

static  void *   zeroed183 (  ) {
    void *  temp184;
    void *  x495 = (  temp184 );
    ( ( memset ) ( ( (  cast_dash_ptr161 ) ( ( & (  x495 ) ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_of135 ) ( (  x495 ) ) ) ) );
    return (  x495 );
}

static  uint32_t   zeroed185 (  ) {
    uint32_t  temp186;
    uint32_t  x495 = (  temp186 );
    ( ( memset ) ( ( (  cast_dash_ptr164 ) ( ( & (  x495 ) ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_of136 ) ( (  x495 ) ) ) ) );
    return (  x495 );
}

static  struct Winsize_138   zeroed187 (  ) {
    struct Winsize_138  temp188;
    struct Winsize_138  x495 = (  temp188 );
    ( ( memset ) ( ( (  cast_dash_ptr165 ) ( ( & (  x495 ) ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_of137 ) ( (  x495 ) ) ) ) );
    return (  x495 );
}

static  FILE *   zeroed189 (  ) {
    FILE *  temp190;
    FILE *  x495 = (  temp190 );
    ( ( memset ) ( ( (  cast_dash_ptr171 ) ( ( & (  x495 ) ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_of139 ) ( (  x495 ) ) ) ) );
    return (  x495 );
}

static  enum Unit_141 *   zeroed191 (  ) {
    enum Unit_141 *  temp192;
    enum Unit_141 *  x495 = (  temp192 );
    ( ( memset ) ( ( (  cast_dash_ptr172 ) ( ( & (  x495 ) ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_of140 ) ( (  x495 ) ) ) ) );
    return (  x495 );
}

static  size_t   zeroed193 (  ) {
    size_t  temp194;
    size_t  x495 = (  temp194 );
    ( ( memset ) ( ( (  cast_dash_ptr173 ) ( ( & (  x495 ) ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_of142 ) ( (  x495 ) ) ) ) );
    return (  x495 );
}

static  char   zeroed195 (  ) {
    char  temp196;
    char  x495 = (  temp196 );
    ( ( memset ) ( ( (  cast_dash_ptr177 ) ( ( & (  x495 ) ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_of143 ) ( (  x495 ) ) ) ) );
    return (  x495 );
}

static  struct Array_145   zeroed197 (  ) {
    struct Array_145  temp198;
    struct Array_145  x495 = (  temp198 );
    ( ( memset ) ( ( (  cast_dash_ptr179 ) ( ( & (  x495 ) ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_of144 ) ( (  x495 ) ) ) ) );
    return (  x495 );
}

static  int64_t   zeroed199 (  ) {
    int64_t  temp200;
    int64_t  x495 = (  temp200 );
    ( ( memset ) ( ( (  cast_dash_ptr180 ) ( ( & (  x495 ) ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_of146 ) ( (  x495 ) ) ) ) );
    return (  x495 );
}

static  struct timespec *   zeroed201 (  ) {
    struct timespec *  temp202;
    struct timespec *  x495 = (  temp202 );
    ( ( memset ) ( ( (  cast_dash_ptr181 ) ( ( & (  x495 ) ) ) ) ,  (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_of147 ) ( (  x495 ) ) ) ) );
    return (  x495 );
}

static  int32_t   cast_dash_on_dash_zeroed203 (    char  x498 ) {
    int32_t  temp204 = ( (  zeroed26 ) ( ) );
    int32_t *  y499 = ( &temp204 );
    char *  yp500 = ( (  cast149 ) ( (  y499 ) ) );
    (*  yp500 ) = (  x498 );
    return ( * (  y499 ) );
}

static  uint32_t   cast_dash_on_dash_zeroed205 (    uint16_t  x498 ) {
    uint32_t  temp206 = ( (  zeroed185 ) ( ) );
    uint32_t *  y499 = ( &temp206 );
    uint16_t *  yp500 = ( (  cast152 ) ( (  y499 ) ) );
    (*  yp500 ) = (  x498 );
    return ( * (  y499 ) );
}

static  size_t   cast_dash_on_dash_zeroed207 (    uint32_t  x498 ) {
    size_t  temp208 = ( (  zeroed193 ) ( ) );
    size_t *  y499 = ( &temp208 );
    uint32_t *  yp500 = ( (  cast154 ) ( (  y499 ) ) );
    (*  yp500 ) = (  x498 );
    return ( * (  y499 ) );
}

static  int64_t   cast_dash_on_dash_zeroed209 (    uint8_t  x498 ) {
    int64_t  temp210 = ( (  zeroed199 ) ( ) );
    int64_t *  y499 = ( &temp210 );
    uint8_t *  yp500 = ( (  cast156 ) ( (  y499 ) ) );
    (*  yp500 ) = (  x498 );
    return ( * (  y499 ) );
}

static  uint32_t   cast_dash_on_dash_zeroed211 (    enum MouseButton_106  x498 ) {
    uint32_t  temp212 = ( (  zeroed185 ) ( ) );
    uint32_t *  y499 = ( &temp212 );
    enum MouseButton_106 *  yp500 = ( (  cast159 ) ( (  y499 ) ) );
    (*  yp500 ) = (  x498 );
    return ( * (  y499 ) );
}

static  int32_t   cast_dash_on_dash_zeroed213 (    uint8_t  x498 ) {
    int32_t  temp214 = ( (  zeroed26 ) ( ) );
    int32_t *  y499 = ( &temp214 );
    uint8_t *  yp500 = ( (  cast160 ) ( (  y499 ) ) );
    (*  yp500 ) = (  x498 );
    return ( * (  y499 ) );
}

static  FILE *   null_dash_ptr215 (  ) {
    return ( (  zeroed189 ) ( ) );
}

static  enum Unit_141 *   null_dash_ptr216 (  ) {
    return ( (  zeroed191 ) ( ) );
}

static  struct timespec *   null_dash_ptr217 (  ) {
    return ( (  zeroed201 ) ( ) );
}

static  void *   null_dash_c_dash_ptr218 (  ) {
    return ( (  zeroed183 ) ( ) );
}

static  bool   ptr_dash_eq219 (    enum Unit_141 *  l511 ,    enum Unit_141 *  r513 ) {
    return ( (  l511 ) == (  r513 ) );
}

struct Maybe_221 {
    enum {
        Maybe_221_None_t,
        Maybe_221_Just_t,
    } tag;
    union {
        struct {
            const char*  field0;
        } Maybe_221_Just_s;
    } stuff;
};

static struct Maybe_221 Maybe_221_Just (  const char*  field0 ) {
    return ( struct Maybe_221 ) { .tag = Maybe_221_Just_t, .stuff = { .Maybe_221_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_221   from_dash_nullable_dash_c_dash_str220 (    const char*  s516 ) {
    if ( ( (  ptr_dash_eq219 ) ( ( (  cast153 ) ( (  s516 ) ) ) ,  ( ( (  null_dash_ptr216 ) ( ) ) ) ) ) ) {
        return ( (struct Maybe_221) { .tag = Maybe_221_None_t } );
    } else {
        return ( ( Maybe_221_Just ) ( (  s516 ) ) );
    }
}

static  int64_t   size_dash_i64222 (    size_t  x519 ) {
    return ( (int64_t ) (  x519 ) );
}

static  uint32_t   i32_dash_u32223 (    int32_t  x525 ) {
    return ( (uint32_t ) (  x525 ) );
}

static  int64_t   i32_dash_i64224 (    int32_t  x528 ) {
    return ( (int64_t ) (  x528 ) );
}

static  size_t   i32_dash_size225 (    int32_t  x531 ) {
    return ( (size_t ) ( (int64_t ) (  x531 ) ) );
}

static  int32_t   i64_dash_i32226 (    int64_t  x537 ) {
    return ( (int32_t ) (  x537 ) );
}

static  size_t   i64_dash_size227 (    int64_t  x543 ) {
    return ( (size_t ) (  x543 ) );
}

static  int32_t   size_dash_i32228 (    size_t  x546 ) {
    return ( (int32_t ) (  x546 ) );
}

static  uint32_t   size_dash_u32229 (    size_t  x549 ) {
    return ( (uint32_t ) (  x549 ) );
}

static  uint32_t   u16_dash_u32230 (    uint16_t  x552 ) {
    return ( (  cast_dash_on_dash_zeroed205 ) ( (  x552 ) ) );
}

static  size_t   u32_dash_size231 (    uint32_t  x558 ) {
    return ( (  cast_dash_on_dash_zeroed207 ) ( (  x558 ) ) );
}

static  int32_t   u32_dash_i32232 (    uint32_t  x567 ) {
    return ( (  cast151 ) ( (  x567 ) ) );
}

static  int64_t   u8_dash_i64233 (    uint8_t  x573 ) {
    return ( (  cast_dash_on_dash_zeroed209 ) ( (  x573 ) ) );
}

static  int32_t   u8_dash_i32234 (    uint8_t  x576 ) {
    return ( (  cast_dash_on_dash_zeroed213 ) ( (  x576 ) ) );
}

struct Slice_238 {
    char *  f_ptr;
    size_t  f_count;
};

struct SliceIter_237 {
    struct Slice_238  f_slice;
    size_t  f_current_dash_offset;
};

struct Scanner_236 {
    struct SliceIter_237  f_s;
};

static  struct Scanner_236   into_dash_iter239 (    struct Scanner_236  self2604 ) {
    return (  self2604 );
}

static  struct Scanner_236   into_dash_iter235 (    struct Scanner_236 *  self582 ) {
    return ( (  into_dash_iter239 ) ( ( * (  self582 ) ) ) );
}

struct ConstStrIter_242 {
    const char*  f_ogstr;
    size_t  f_i;
};

struct Map_241 {
    struct ConstStrIter_242  field0;
    uint32_t (*  field1 )(    char  );
};

static struct Map_241 Map_241_Map (  struct ConstStrIter_242  field0 ,  uint32_t (*  field1 )(    char  ) ) {
    return ( struct Map_241 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct Map_241   into_dash_iter240 (    struct Map_241  self593 ) {
    return (  self593 );
}

struct Maybe_244 {
    enum {
        Maybe_244_None_t,
        Maybe_244_Just_t,
    } tag;
    union {
        struct {
            uint32_t  field0;
        } Maybe_244_Just_s;
    } stuff;
};

static struct Maybe_244 Maybe_244_Just (  uint32_t  field0 ) {
    return ( struct Maybe_244 ) { .tag = Maybe_244_Just_t, .stuff = { .Maybe_244_Just_s = { .field0 = field0 } } };
};

struct Maybe_245 {
    enum {
        Maybe_245_None_t,
        Maybe_245_Just_t,
    } tag;
    union {
        struct {
            char  field0;
        } Maybe_245_Just_s;
    } stuff;
};

static struct Maybe_245 Maybe_245_Just (  char  field0 ) {
    return ( struct Maybe_245 ) { .tag = Maybe_245_Just_t, .stuff = { .Maybe_245_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_245   next246 (    struct ConstStrIter_242 *  self1105 ) {
    if ( (  cmp38 ( ( ( * (  self1105 ) ) .f_i ) , ( (  i32_dash_size225 ) ( ( ( strlen ) ( ( ( * (  self1105 ) ) .f_ogstr ) ) ) ) ) ) != 0 ) ) {
        return ( (struct Maybe_245) { .tag = Maybe_245_None_t } );
    }
    char *  char_dash_ptr1106 = ( ( (  cast150 ) ( ( ( * (  self1105 ) ) .f_ogstr ) ) ) );
    char  c1107 = ( * ( (  offset_dash_ptr114 ) ( (  char_dash_ptr1106 ) ,  ( (  size_dash_i64222 ) ( ( ( * (  self1105 ) ) .f_i ) ) ) ) ) );
    (*  self1105 ) .f_i = (  op_dash_add57 ( ( ( * (  self1105 ) ) .f_i ) , (  from_dash_integral7 ( 1 ) ) ) );
    return ( ( Maybe_245_Just ) ( (  c1107 ) ) );
}

static  struct Maybe_244   next243 (    struct Map_241 *  dref595 ) {
    struct Maybe_245  dref598 = ( (  next246 ) ( ( & ( (* dref595 ) .field0 ) ) ) );
    if ( dref598.tag == Maybe_245_None_t ) {
        return ( (struct Maybe_244) { .tag = Maybe_244_None_t } );
    }
    else {
        if ( dref598.tag == Maybe_245_Just_t ) {
            return ( ( Maybe_244_Just ) ( ( ( (* dref595 ) .field1 ) ( ( dref598 .stuff .Maybe_245_Just_s .field0 ) ) ) ) );
        }
    }
}

static  struct ConstStrIter_242   into_dash_iter248 (    const char*  self1099 ) {
    return ( (struct ConstStrIter_242) { .f_ogstr = (  self1099 ) , .f_i = (  from_dash_integral7 ( 0 ) ) } );
}

static  struct Map_241   map247 (    const char*  iterable602 ,    uint32_t (*  fun604 )(    char  ) ) {
    struct ConstStrIter_242  it605 = ( (  into_dash_iter248 ) ( (  iterable602 ) ) );
    return ( ( Map_241_Map ) ( (  it605 ) ,  (  fun604 ) ) );
}

struct Range_250 {
    int32_t  field0;
    int32_t  field1;
};

static struct Range_250 Range_250_Range (  int32_t  field0 ,  int32_t  field1 ) {
    return ( struct Range_250 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct Range_250   to249 (    int32_t  from671 ,    int32_t  to673 ) {
    return ( ( Range_250_Range ) ( (  from671 ) ,  (  to673 ) ) );
}

struct RangeIter_252 {
    struct Range_250  field0;
    int32_t  field1;
};

static struct RangeIter_252 RangeIter_252_RangeIter (  struct Range_250  field0 ,  int32_t  field1 ) {
    return ( struct RangeIter_252 ) { .field0 = field0 ,  .field1 = field1 };
};

static  struct RangeIter_252   into_dash_iter251 (    struct Range_250  dref680 ) {
    return ( ( RangeIter_252_RangeIter ) ( ( ( Range_250_Range ) ( ( dref680 .field0 ) ,  ( dref680 .field1 ) ) ) ,  ( dref680 .field0 ) ) );
}

struct Maybe_254 {
    enum {
        Maybe_254_None_t,
        Maybe_254_Just_t,
    } tag;
    union {
        struct {
            int32_t  field0;
        } Maybe_254_Just_s;
    } stuff;
};

static struct Maybe_254 Maybe_254_Just (  int32_t  field0 ) {
    return ( struct Maybe_254 ) { .tag = Maybe_254_Just_t, .stuff = { .Maybe_254_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_254   next253 (    struct RangeIter_252 *  self688 ) {
    struct RangeIter_252  dref689 = ( * (  self688 ) );
    if ( true ) {
        if ( (  cmp39 ( ( dref689 .field1 ) , ( dref689 .field0 .field1 ) ) == 2 ) ) {
            return ( (struct Maybe_254) { .tag = Maybe_254_None_t } );
        }
        struct Maybe_254  x693 = ( ( Maybe_254_Just ) ( ( dref689 .field1 ) ) );
        (*  self688 ) = ( ( RangeIter_252_RangeIter ) ( ( ( Range_250_Range ) ( ( dref689 .field0 .field0 ) ,  ( dref689 .field0 .field1 ) ) ) ,  (  op_dash_add46 ( ( dref689 .field1 ) , (  from_dash_integral2 ( 1 ) ) ) ) ) );
        return (  x693 );
    }
}

struct FromIter_256 {
    int32_t  f_from;
};

static  struct FromIter_256   from255 (    int32_t  f697 ) {
    return ( (struct FromIter_256) { .f_from = (  f697 ) } );
}

static  struct FromIter_256   into_dash_iter257 (    struct FromIter_256  it700 ) {
    return (  it700 );
}

static  struct Maybe_254   next258 (    struct FromIter_256 *  dref702 ) {
    int32_t  v704 = ( ( (* dref702 ) ) .f_from );
    (* dref702 ) .f_from = (  op_dash_add46 ( ( ( (* dref702 ) ) .f_from ) , (  from_dash_integral2 ( 1 ) ) ) );
    return ( ( Maybe_254_Just ) ( (  v704 ) ) );
}

struct Slice_262 {
    struct Slice_90 *  f_ptr;
    size_t  f_count;
};

struct SliceIter_261 {
    struct Slice_262  f_slice;
    size_t  f_current_dash_offset;
};

struct Zip_260 {
    struct SliceIter_261  f_left_dash_it;
    struct FromIter_256  f_right_dash_it;
};

static  struct Zip_260   into_dash_iter259 (    struct Zip_260  self708 ) {
    return (  self708 );
}

struct SliceIter_265 {
    struct Slice_90  f_slice;
    size_t  f_current_dash_offset;
};

struct Zip_264 {
    struct SliceIter_265  f_left_dash_it;
    struct FromIter_256  f_right_dash_it;
};

static  struct Zip_264   into_dash_iter263 (    struct Zip_264  self708 ) {
    return (  self708 );
}

struct Zip_267 {
    struct ConstStrIter_242  f_left_dash_it;
    struct FromIter_256  f_right_dash_it;
};

static  struct Zip_267   into_dash_iter266 (    struct Zip_267  self708 ) {
    return (  self708 );
}

struct Tuple2_270 {
    struct Slice_90  field0;
    int32_t  field1;
};

static struct Tuple2_270 Tuple2_270_Tuple2 (  struct Slice_90  field0 ,  int32_t  field1 ) {
    return ( struct Tuple2_270 ) { .field0 = field0 ,  .field1 = field1 };
};

struct Maybe_269 {
    enum {
        Maybe_269_None_t,
        Maybe_269_Just_t,
    } tag;
    union {
        struct {
            struct Tuple2_270  field0;
        } Maybe_269_Just_s;
    } stuff;
};

static struct Maybe_269 Maybe_269_Just (  struct Tuple2_270  field0 ) {
    return ( struct Maybe_269 ) { .tag = Maybe_269_Just_t, .stuff = { .Maybe_269_Just_s = { .field0 = field0 } } };
};

struct Maybe_271 {
    enum {
        Maybe_271_None_t,
        Maybe_271_Just_t,
    } tag;
    union {
        struct {
            struct Slice_90  field0;
        } Maybe_271_Just_s;
    } stuff;
};

static struct Maybe_271 Maybe_271_Just (  struct Slice_90  field0 ) {
    return ( struct Maybe_271 ) { .tag = Maybe_271_Just_t, .stuff = { .Maybe_271_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_271   next272 (    struct SliceIter_261 *  self1500 ) {
    size_t  off1501 = ( ( * (  self1500 ) ) .f_current_dash_offset );
    if ( (  cmp38 ( (  op_dash_add57 ( (  off1501 ) , (  from_dash_integral7 ( 1 ) ) ) ) , ( ( ( * (  self1500 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_271) { .tag = Maybe_271_None_t } );
    }
    struct Slice_90  elem1502 = ( * ( (  offset_dash_ptr116 ) ( ( ( ( * (  self1500 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  off1501 ) ) ) ) ) );
    (*  self1500 ) .f_current_dash_offset = (  op_dash_add57 ( (  off1501 ) , (  from_dash_integral7 ( 1 ) ) ) );
    return ( ( Maybe_271_Just ) ( (  elem1502 ) ) );
}

static  struct Maybe_269   next268 (    struct Zip_260 *  self711 ) {
    struct Zip_260  copy712 = ( * (  self711 ) );
    while ( ( true ) ) {
        struct Maybe_271  dref713 = ( (  next272 ) ( ( & ( (  copy712 ) .f_left_dash_it ) ) ) );
        if ( dref713.tag == Maybe_271_None_t ) {
            return ( (struct Maybe_269) { .tag = Maybe_269_None_t } );
        }
        else {
            if ( dref713.tag == Maybe_271_Just_t ) {
                struct Maybe_254  dref715 = ( (  next258 ) ( ( & ( (  copy712 ) .f_right_dash_it ) ) ) );
                if ( dref715.tag == Maybe_254_None_t ) {
                    return ( (struct Maybe_269) { .tag = Maybe_269_None_t } );
                }
                else {
                    if ( dref715.tag == Maybe_254_Just_t ) {
                        ( (  next272 ) ( ( & ( ( * (  self711 ) ) .f_left_dash_it ) ) ) );
                        ( (  next258 ) ( ( & ( ( * (  self711 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_269_Just ) ( ( ( Tuple2_270_Tuple2 ) ( ( dref713 .stuff .Maybe_271_Just_s .field0 ) ,  ( dref715 .stuff .Maybe_254_Just_s .field0 ) ) ) ) );
                    }
                }
            }
        }
    }
}

struct Tuple2_275 {
    struct Tile_91  field0;
    int32_t  field1;
};

static struct Tuple2_275 Tuple2_275_Tuple2 (  struct Tile_91  field0 ,  int32_t  field1 ) {
    return ( struct Tuple2_275 ) { .field0 = field0 ,  .field1 = field1 };
};

struct Maybe_274 {
    enum {
        Maybe_274_None_t,
        Maybe_274_Just_t,
    } tag;
    union {
        struct {
            struct Tuple2_275  field0;
        } Maybe_274_Just_s;
    } stuff;
};

static struct Maybe_274 Maybe_274_Just (  struct Tuple2_275  field0 ) {
    return ( struct Maybe_274 ) { .tag = Maybe_274_Just_t, .stuff = { .Maybe_274_Just_s = { .field0 = field0 } } };
};

struct Maybe_276 {
    enum {
        Maybe_276_None_t,
        Maybe_276_Just_t,
    } tag;
    union {
        struct {
            struct Tile_91  field0;
        } Maybe_276_Just_s;
    } stuff;
};

static struct Maybe_276 Maybe_276_Just (  struct Tile_91  field0 ) {
    return ( struct Maybe_276 ) { .tag = Maybe_276_Just_t, .stuff = { .Maybe_276_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_276   next277 (    struct SliceIter_265 *  self1500 ) {
    size_t  off1501 = ( ( * (  self1500 ) ) .f_current_dash_offset );
    if ( (  cmp38 ( (  op_dash_add57 ( (  off1501 ) , (  from_dash_integral7 ( 1 ) ) ) ) , ( ( ( * (  self1500 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    struct Tile_91  elem1502 = ( * ( (  offset_dash_ptr118 ) ( ( ( ( * (  self1500 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  off1501 ) ) ) ) ) );
    (*  self1500 ) .f_current_dash_offset = (  op_dash_add57 ( (  off1501 ) , (  from_dash_integral7 ( 1 ) ) ) );
    return ( ( Maybe_276_Just ) ( (  elem1502 ) ) );
}

static  struct Maybe_274   next273 (    struct Zip_264 *  self711 ) {
    struct Zip_264  copy712 = ( * (  self711 ) );
    while ( ( true ) ) {
        struct Maybe_276  dref713 = ( (  next277 ) ( ( & ( (  copy712 ) .f_left_dash_it ) ) ) );
        if ( dref713.tag == Maybe_276_None_t ) {
            return ( (struct Maybe_274) { .tag = Maybe_274_None_t } );
        }
        else {
            if ( dref713.tag == Maybe_276_Just_t ) {
                struct Maybe_254  dref715 = ( (  next258 ) ( ( & ( (  copy712 ) .f_right_dash_it ) ) ) );
                if ( dref715.tag == Maybe_254_None_t ) {
                    return ( (struct Maybe_274) { .tag = Maybe_274_None_t } );
                }
                else {
                    if ( dref715.tag == Maybe_254_Just_t ) {
                        ( (  next277 ) ( ( & ( ( * (  self711 ) ) .f_left_dash_it ) ) ) );
                        ( (  next258 ) ( ( & ( ( * (  self711 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_274_Just ) ( ( ( Tuple2_275_Tuple2 ) ( ( dref713 .stuff .Maybe_276_Just_s .field0 ) ,  ( dref715 .stuff .Maybe_254_Just_s .field0 ) ) ) ) );
                    }
                }
            }
        }
    }
}

struct Tuple2_280 {
    char  field0;
    int32_t  field1;
};

static struct Tuple2_280 Tuple2_280_Tuple2 (  char  field0 ,  int32_t  field1 ) {
    return ( struct Tuple2_280 ) { .field0 = field0 ,  .field1 = field1 };
};

struct Maybe_279 {
    enum {
        Maybe_279_None_t,
        Maybe_279_Just_t,
    } tag;
    union {
        struct {
            struct Tuple2_280  field0;
        } Maybe_279_Just_s;
    } stuff;
};

static struct Maybe_279 Maybe_279_Just (  struct Tuple2_280  field0 ) {
    return ( struct Maybe_279 ) { .tag = Maybe_279_Just_t, .stuff = { .Maybe_279_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_279   next278 (    struct Zip_267 *  self711 ) {
    struct Zip_267  copy712 = ( * (  self711 ) );
    while ( ( true ) ) {
        struct Maybe_245  dref713 = ( (  next246 ) ( ( & ( (  copy712 ) .f_left_dash_it ) ) ) );
        if ( dref713.tag == Maybe_245_None_t ) {
            return ( (struct Maybe_279) { .tag = Maybe_279_None_t } );
        }
        else {
            if ( dref713.tag == Maybe_245_Just_t ) {
                struct Maybe_254  dref715 = ( (  next258 ) ( ( & ( (  copy712 ) .f_right_dash_it ) ) ) );
                if ( dref715.tag == Maybe_254_None_t ) {
                    return ( (struct Maybe_279) { .tag = Maybe_279_None_t } );
                }
                else {
                    if ( dref715.tag == Maybe_254_Just_t ) {
                        ( (  next246 ) ( ( & ( ( * (  self711 ) ) .f_left_dash_it ) ) ) );
                        ( (  next258 ) ( ( & ( ( * (  self711 ) ) .f_right_dash_it ) ) ) );
                        return ( ( Maybe_279_Just ) ( ( ( Tuple2_280_Tuple2 ) ( ( dref713 .stuff .Maybe_245_Just_s .field0 ) ,  ( dref715 .stuff .Maybe_254_Just_s .field0 ) ) ) ) );
                    }
                }
            }
        }
    }
}

static  struct SliceIter_261   into_dash_iter282 (    struct Slice_262  self1494 ) {
    return ( (struct SliceIter_261) { .f_slice = (  self1494 ) , .f_current_dash_offset = (  from_dash_integral7 ( 0 ) ) } );
}

static  struct Zip_260   zip281 (    struct Slice_262  left719 ,    struct FromIter_256  right721 ) {
    struct SliceIter_261  left_dash_it722 = ( (  into_dash_iter282 ) ( (  left719 ) ) );
    struct FromIter_256  right_dash_it723 = ( (  into_dash_iter257 ) ( (  right721 ) ) );
    return ( (struct Zip_260) { .f_left_dash_it = (  left_dash_it722 ) , .f_right_dash_it = (  right_dash_it723 ) } );
}

static  struct SliceIter_265   into_dash_iter284 (    struct Slice_90  self1494 ) {
    return ( (struct SliceIter_265) { .f_slice = (  self1494 ) , .f_current_dash_offset = (  from_dash_integral7 ( 0 ) ) } );
}

static  struct Zip_264   zip283 (    struct Slice_90  left719 ,    struct FromIter_256  right721 ) {
    struct SliceIter_265  left_dash_it722 = ( (  into_dash_iter284 ) ( (  left719 ) ) );
    struct FromIter_256  right_dash_it723 = ( (  into_dash_iter257 ) ( (  right721 ) ) );
    return ( (struct Zip_264) { .f_left_dash_it = (  left_dash_it722 ) , .f_right_dash_it = (  right_dash_it723 ) } );
}

static  struct ConstStrIter_242   into_dash_iter286 (    struct ConstStrIter_242  self1102 ) {
    return (  self1102 );
}

static  struct Zip_267   zip285 (    struct ConstStrIter_242  left719 ,    struct FromIter_256  right721 ) {
    struct ConstStrIter_242  left_dash_it722 = ( (  into_dash_iter286 ) ( (  left719 ) ) );
    struct FromIter_256  right_dash_it723 = ( (  into_dash_iter257 ) ( (  right721 ) ) );
    return ( (struct Zip_267) { .f_left_dash_it = (  left_dash_it722 ) , .f_right_dash_it = (  right_dash_it723 ) } );
}

struct FlattenIter_288 {
    struct SliceIter_261  f_super;
    struct SliceIter_265  f_inner;
    bool  f_empty;
};

static  struct FlattenIter_288   into_dash_iter287 (    struct FlattenIter_288  self727 ) {
    return (  self727 );
}

static  struct Maybe_276   next289 (    struct FlattenIter_288 *  self730 ) {
    if ( ( ( * (  self730 ) ) .f_empty ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    while ( ( true ) ) {
        struct Maybe_276  dref731 = ( (  next277 ) ( ( & ( ( * (  self730 ) ) .f_inner ) ) ) );
        if ( dref731.tag == Maybe_276_Just_t ) {
            return ( ( Maybe_276_Just ) ( ( dref731 .stuff .Maybe_276_Just_s .field0 ) ) );
        }
        else {
            if ( dref731.tag == Maybe_276_None_t ) {
                struct Maybe_271  dref733 = ( (  next272 ) ( ( & ( ( * (  self730 ) ) .f_super ) ) ) );
                if ( dref733.tag == Maybe_271_Just_t ) {
                    (*  self730 ) .f_inner = ( (  into_dash_iter284 ) ( ( dref733 .stuff .Maybe_271_Just_s .field0 ) ) );
                }
                else {
                    if ( dref733.tag == Maybe_271_None_t ) {
                        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
                    }
                }
            }
        }
    }
}

static  struct FlattenIter_288   flatten290 (    struct Slice_262  it737 ) {
    struct SliceIter_261  it738 = ( (  into_dash_iter282 ) ( (  it737 ) ) );
    struct Maybe_271  dref739 = ( (  next272 ) ( ( & (  it738 ) ) ) );
    if ( dref739.tag == Maybe_271_Just_t ) {
        return ( (struct FlattenIter_288) { .f_super = (  it738 ) , .f_inner = ( (  into_dash_iter284 ) ( ( dref739 .stuff .Maybe_271_Just_s .field0 ) ) ) , .f_empty = ( false ) } );
    }
    else {
        if ( dref739.tag == Maybe_271_None_t ) {
            struct SliceIter_265  temp291;
            return ( (struct FlattenIter_288) { .f_super = (  it738 ) , .f_inner = (  temp291 ) , .f_empty = ( true ) } );
        }
    }
}

struct TakeWhile_293 {
    struct Scanner_236  f_it;
    bool (*  f_pred )(    char  );
};

static  struct TakeWhile_293   into_dash_iter292 (    struct TakeWhile_293  self758 ) {
    return (  self758 );
}

static  struct Maybe_245   next296 (    struct SliceIter_237 *  self1500 ) {
    size_t  off1501 = ( ( * (  self1500 ) ) .f_current_dash_offset );
    if ( (  cmp38 ( (  op_dash_add57 ( (  off1501 ) , (  from_dash_integral7 ( 1 ) ) ) ) , ( ( ( * (  self1500 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_245) { .tag = Maybe_245_None_t } );
    }
    char  elem1502 = ( * ( (  offset_dash_ptr114 ) ( ( ( ( * (  self1500 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  off1501 ) ) ) ) ) );
    (*  self1500 ) .f_current_dash_offset = (  op_dash_add57 ( (  off1501 ) , (  from_dash_integral7 ( 1 ) ) ) );
    return ( ( Maybe_245_Just ) ( (  elem1502 ) ) );
}

static  struct Maybe_245   next295 (    struct Scanner_236 *  self2601 ) {
    return ( (  next296 ) ( ( & ( ( * (  self2601 ) ) .f_s ) ) ) );
}

static  struct Maybe_245   next294 (    struct TakeWhile_293 *  self761 ) {
    struct Maybe_245  mx762 = ( (  next295 ) ( ( & ( ( * (  self761 ) ) .f_it ) ) ) );
    struct Maybe_245  dref763 = (  mx762 );
    if ( dref763.tag == Maybe_245_None_t ) {
        return ( (struct Maybe_245) { .tag = Maybe_245_None_t } );
    }
    else {
        if ( dref763.tag == Maybe_245_Just_t ) {
            if ( ( ( ( * (  self761 ) ) .f_pred ) ( ( dref763 .stuff .Maybe_245_Just_s .field0 ) ) ) ) {
                return ( ( Maybe_245_Just ) ( ( dref763 .stuff .Maybe_245_Just_s .field0 ) ) );
            } else {
                return ( (struct Maybe_245) { .tag = Maybe_245_None_t } );
            }
        }
    }
}

static  struct TakeWhile_293   take_dash_while297 (    struct Scanner_236 *  it767 ,    bool (*  pred769 )(    char  ) ) {
    return ( (struct TakeWhile_293) { .f_it = ( (  into_dash_iter235 ) ( (  it767 ) ) ) , .f_pred = (  pred769 ) } );
}

struct Key_302 {
    enum {
        Key_302_Escape_t,
        Key_302_Enter_t,
        Key_302_Tab_t,
        Key_302_Backspace_t,
        Key_302_Char_t,
        Key_302_Ctrl_t,
        Key_302_Up_t,
        Key_302_Down_t,
        Key_302_Left_t,
        Key_302_Right_t,
        Key_302_Home_t,
        Key_302_End_t,
        Key_302_PageUp_t,
        Key_302_PageDown_t,
        Key_302_Delete_t,
        Key_302_Insert_t,
        Key_302_F1_t,
        Key_302_F2_t,
        Key_302_F3_t,
        Key_302_F4_t,
        Key_302_F5_t,
        Key_302_F6_t,
        Key_302_F7_t,
        Key_302_F8_t,
        Key_302_F9_t,
        Key_302_F10_t,
        Key_302_F11_t,
        Key_302_F12_t,
    } tag;
    union {
        struct {
            char  field0;
        } Key_302_Char_s;
        struct {
            char  field0;
        } Key_302_Ctrl_s;
    } stuff;
};

static struct Key_302 Key_302_Char (  char  field0 ) {
    return ( struct Key_302 ) { .tag = Key_302_Char_t, .stuff = { .Key_302_Char_s = { .field0 = field0 } } };
};

static struct Key_302 Key_302_Ctrl (  char  field0 ) {
    return ( struct Key_302 ) { .tag = Key_302_Ctrl_t, .stuff = { .Key_302_Ctrl_s = { .field0 = field0 } } };
};

struct MouseEvent_303 {
    enum MouseButton_106  f_button;
    int32_t  f_x;
    int32_t  f_y;
    bool  f_pressed;
};

struct InputEvent_301 {
    enum {
        InputEvent_301_Key_t,
        InputEvent_301_Mouse_t,
    } tag;
    union {
        struct {
            struct Key_302  field0;
        } InputEvent_301_Key_s;
        struct {
            struct MouseEvent_303  field0;
        } InputEvent_301_Mouse_s;
    } stuff;
};

static struct InputEvent_301 InputEvent_301_Key (  struct Key_302  field0 ) {
    return ( struct InputEvent_301 ) { .tag = InputEvent_301_Key_t, .stuff = { .InputEvent_301_Key_s = { .field0 = field0 } } };
};

static struct InputEvent_301 InputEvent_301_Mouse (  struct MouseEvent_303  field0 ) {
    return ( struct InputEvent_301 ) { .tag = InputEvent_301_Mouse_t, .stuff = { .InputEvent_301_Mouse_s = { .field0 = field0 } } };
};

struct Maybe_300 {
    enum {
        Maybe_300_None_t,
        Maybe_300_Just_t,
    } tag;
    union {
        struct {
            struct InputEvent_301  field0;
        } Maybe_300_Just_s;
    } stuff;
};

static struct Maybe_300 Maybe_300_Just (  struct InputEvent_301  field0 ) {
    return ( struct Maybe_300 ) { .tag = Maybe_300_Just_t, .stuff = { .Maybe_300_Just_s = { .field0 = field0 } } };
};

struct FunIter_299 {
    struct Maybe_300 (*  f_fun )(  );
    bool  f_finished;
};

static  struct FunIter_299   into_dash_iter298 (    struct FunIter_299  self825 ) {
    return (  self825 );
}

static  struct Maybe_300   next304 (    struct FunIter_299 *  self828 ) {
    if ( ( ( * (  self828 ) ) .f_finished ) ) {
        return ( (struct Maybe_300) { .tag = Maybe_300_None_t } );
    }
    struct Maybe_300  dref829 = ( ( ( * (  self828 ) ) .f_fun ) ( ) );
    if ( dref829.tag == Maybe_300_Just_t ) {
        return ( ( Maybe_300_Just ) ( ( dref829 .stuff .Maybe_300_Just_s .field0 ) ) );
    }
    else {
        if ( dref829.tag == Maybe_300_None_t ) {
            (*  self828 ) .f_finished = ( true );
            return ( (struct Maybe_300) { .tag = Maybe_300_None_t } );
        }
    }
}

static  struct FunIter_299   from_dash_function305 (    struct Maybe_300 (*  fun833 )(  ) ) {
    return ( (struct FunIter_299) { .f_fun = (  fun833 ) , .f_finished = ( false ) } );
}

struct env308 {
    struct Tile_91  x1623;
};

struct funenv308 {
    struct Tile_91  (*fun) (  struct env308  ,    struct Tile_91  );
    struct env308 env;
};

struct env307 {
    struct Slice_90  s1577;
    ;
    ;
    struct funenv308  fun1579;
    ;
};

struct funenv307 {
    enum Unit_141  (*fun) (  struct env307  ,    int32_t  );
    struct env307 env;
};

static  enum Unit_141   for_dash_each306 (    struct Range_250  iterable836 ,   struct funenv307  fun838 ) {
    struct RangeIter_252  temp309 = ( (  into_dash_iter251 ) ( (  iterable836 ) ) );
    struct RangeIter_252 *  it839 = ( &temp309 );
    while ( ( true ) ) {
        struct Maybe_254  dref840 = ( (  next253 ) ( (  it839 ) ) );
        if ( dref840.tag == Maybe_254_None_t ) {
            return ( Unit_141_Unit );
        }
        else {
            if ( dref840.tag == Maybe_254_Just_t ) {
                struct funenv307  temp310 = (  fun838 );
                ( temp310.fun ( temp310.env ,  ( dref840 .stuff .Maybe_254_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_141_Unit );
}

struct Slice_313 {
    struct Cell_15 *  f_ptr;
    size_t  f_count;
};

struct env312 {
    struct Slice_313  s1577;
    ;
    ;
    struct Cell_15 (*  fun1579 )(    struct Cell_15  );
    ;
};

struct funenv312 {
    enum Unit_141  (*fun) (  struct env312  ,    int32_t  );
    struct env312 env;
};

static  enum Unit_141   for_dash_each311 (    struct Range_250  iterable836 ,   struct funenv312  fun838 ) {
    struct RangeIter_252  temp314 = ( (  into_dash_iter251 ) ( (  iterable836 ) ) );
    struct RangeIter_252 *  it839 = ( &temp314 );
    while ( ( true ) ) {
        struct Maybe_254  dref840 = ( (  next253 ) ( (  it839 ) ) );
        if ( dref840.tag == Maybe_254_None_t ) {
            return ( Unit_141_Unit );
        }
        else {
            if ( dref840.tag == Maybe_254_Just_t ) {
                struct funenv312  temp315 = (  fun838 );
                ( temp315.fun ( temp315.env ,  ( dref840 .stuff .Maybe_254_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_141_Unit );
}

struct env317 {
    struct Slice_313  s1577;
    ;
    ;
    struct Cell_15 (*  fun1579 )(    struct Cell_15  );
    ;
};

struct funenv317 {
    enum Unit_141  (*fun) (  struct env317  ,    int32_t  );
    struct env317 env;
};

static  enum Unit_141   for_dash_each316 (    struct Range_250  iterable836 ,   struct funenv317  fun838 ) {
    struct RangeIter_252  temp318 = ( (  into_dash_iter251 ) ( (  iterable836 ) ) );
    struct RangeIter_252 *  it839 = ( &temp318 );
    while ( ( true ) ) {
        struct Maybe_254  dref840 = ( (  next253 ) ( (  it839 ) ) );
        if ( dref840.tag == Maybe_254_None_t ) {
            return ( Unit_141_Unit );
        }
        else {
            if ( dref840.tag == Maybe_254_Just_t ) {
                struct funenv317  temp319 = (  fun838 );
                ( temp319.fun ( temp319.env ,  ( dref840 .stuff .Maybe_254_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_141_Unit );
}

struct env321 {
    ;
    struct Scanner_236 *  it942;
};

struct funenv321 {
    struct Maybe_245  (*fun) (  struct env321  ,    int32_t  );
    struct env321 env;
};

static  enum Unit_141   for_dash_each320 (    struct Range_250  iterable836 ,   struct funenv321  fun838 ) {
    struct RangeIter_252  temp322 = ( (  into_dash_iter251 ) ( (  iterable836 ) ) );
    struct RangeIter_252 *  it839 = ( &temp322 );
    while ( ( true ) ) {
        struct Maybe_254  dref840 = ( (  next253 ) ( (  it839 ) ) );
        if ( dref840.tag == Maybe_254_None_t ) {
            return ( Unit_141_Unit );
        }
        else {
            if ( dref840.tag == Maybe_254_Just_t ) {
                struct funenv321  temp323 = (  fun838 );
                ( temp323.fun ( temp323.env ,  ( dref840 .stuff .Maybe_254_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_141_Unit );
}

struct env325 {
    struct Slice_313  s1577;
    ;
    ;
    struct Cell_15 (*  fun1579 )(    struct Cell_15  );
    ;
};

struct funenv325 {
    enum Unit_141  (*fun) (  struct env325  ,    int32_t  );
    struct env325 env;
};

static  enum Unit_141   for_dash_each324 (    struct Range_250  iterable836 ,   struct funenv325  fun838 ) {
    struct RangeIter_252  temp326 = ( (  into_dash_iter251 ) ( (  iterable836 ) ) );
    struct RangeIter_252 *  it839 = ( &temp326 );
    while ( ( true ) ) {
        struct Maybe_254  dref840 = ( (  next253 ) ( (  it839 ) ) );
        if ( dref840.tag == Maybe_254_None_t ) {
            return ( Unit_141_Unit );
        }
        else {
            if ( dref840.tag == Maybe_254_Just_t ) {
                struct funenv325  temp327 = (  fun838 );
                ( temp327.fun ( temp327.env ,  ( dref840 .stuff .Maybe_254_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_141_Unit );
}

enum CAllocator_331 {
    CAllocator_331_CAllocator,
};

enum ColorPalette_333 {
    ColorPalette_333_Palette8,
    ColorPalette_333_Palette16,
    ColorPalette_333_Palette256,
    ColorPalette_333_PaletteRGB,
};

struct Tui_332 {
    uint32_t  f_width;
    uint32_t  f_height;
    uint32_t  f_target_dash_fps;
    uint32_t  f_actual_dash_fps;
    enum ColorPalette_333  f_palette;
    struct timespec  f_last_dash_sync;
    struct timespec  f_fps_dash_ts;
    uint32_t  f_fps_dash_count;
    struct Termios_96  f_orig_dash_termios;
};

struct Screen_330 {
    enum CAllocator_331  f_al;
    struct Tui_332 *  f_tui;
    struct Slice_313  f_current;
    struct Slice_313  f_previous;
    bool  f_requires_dash_full_dash_redraw;
    struct Color_16  f_default_dash_fg;
    struct Color_16  f_default_dash_bg;
};

struct env329 {
    ;
    int32_t  y2873;
    struct Screen_330 *  screen2867;
    int32_t  x2876;
    ;
};

struct funenv329 {
    enum Unit_141  (*fun) (  struct env329  ,    struct Tuple2_280  );
    struct env329 env;
};

static  enum Unit_141   for_dash_each328 (    struct Zip_267  iterable836 ,   struct funenv329  fun838 ) {
    struct Zip_267  temp334 = ( (  into_dash_iter266 ) ( (  iterable836 ) ) );
    struct Zip_267 *  it839 = ( &temp334 );
    while ( ( true ) ) {
        struct Maybe_279  dref840 = ( (  next278 ) ( (  it839 ) ) );
        if ( dref840.tag == Maybe_279_None_t ) {
            return ( Unit_141_Unit );
        }
        else {
            if ( dref840.tag == Maybe_279_Just_t ) {
                struct funenv329  temp335 = (  fun838 );
                ( temp335.fun ( temp335.env ,  ( dref840 .stuff .Maybe_279_Just_s .field0 ) ) );
            }
        }
    }
    return ( Unit_141_Unit );
}

struct Maybe_337 {
    enum {
        Maybe_337_None_t,
        Maybe_337_Just_t,
    } tag;
    union {
        struct {
            int64_t  field0;
        } Maybe_337_Just_s;
    } stuff;
};

static struct Maybe_337 Maybe_337_Just (  int64_t  field0 ) {
    return ( struct Maybe_337 ) { .tag = Maybe_337_Just_t, .stuff = { .Maybe_337_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_337   reduce336 (    struct ConstStrIter_242  iterable855 ,    struct Maybe_337  base857 ,    struct Maybe_337 (*  fun859 )(    char  ,    struct Maybe_337  ) ) {
    struct Maybe_337  x860 = (  base857 );
    struct ConstStrIter_242  it861 = ( (  into_dash_iter286 ) ( (  iterable855 ) ) );
    while ( ( true ) ) {
        struct Maybe_245  dref862 = ( (  next246 ) ( ( & (  it861 ) ) ) );
        if ( dref862.tag == Maybe_245_None_t ) {
            return (  x860 );
        }
        else {
            if ( dref862.tag == Maybe_245_Just_t ) {
                x860 = ( (  fun859 ) ( ( dref862 .stuff .Maybe_245_Just_s .field0 ) ,  (  x860 ) ) );
            }
        }
    }
    struct Maybe_337  temp338;
    return (  temp338 );
}

struct SmolArrayIter_340 {
    struct SmolArray_61  f_backing;
    size_t  f_cur;
};

static  struct SmolArrayIter_340   into_dash_iter341 (    struct SmolArray_61  self1735 ) {
    return ( (struct SmolArrayIter_340) { .f_backing = (  self1735 ) , .f_cur = (  from_dash_integral7 ( 0 ) ) } );
}

struct StrConcat_349 {
    const char*  field0;
    size_t  field1;
};

static struct StrConcat_349 StrConcat_349_StrConcat (  const char*  field0 ,  size_t  field1 ) {
    return ( struct StrConcat_349 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_348 {
    struct StrConcat_349  field0;
    const char*  field1;
};

static struct StrConcat_348 StrConcat_348_StrConcat (  struct StrConcat_349  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_348 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_347 {
    struct StrConcat_348  field0;
    int32_t  field1;
};

static struct StrConcat_347 StrConcat_347_StrConcat (  struct StrConcat_348  field0 ,  int32_t  field1 ) {
    return ( struct StrConcat_347 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_346 {
    struct StrConcat_347  field0;
    char  field1;
};

static struct StrConcat_346 StrConcat_346_StrConcat (  struct StrConcat_347  field0 ,  char  field1 ) {
    return ( struct StrConcat_346 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_352 {
    const char*  field0;
    struct StrConcat_346  field1;
};

static struct StrConcat_352 StrConcat_352_StrConcat (  const char*  field0 ,  struct StrConcat_346  field1 ) {
    return ( struct StrConcat_352 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_351 {
    struct StrConcat_352  field0;
    char  field1;
};

static struct StrConcat_351 StrConcat_351_StrConcat (  struct StrConcat_352  field0 ,  char  field1 ) {
    return ( struct StrConcat_351 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_141   print_dash_str354 (    const char*  self1110 ) {
    ( ( printf ) ( ( "%s" ) ,  (  self1110 ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str359 (    size_t  self1167 ) {
    ( ( printf ) ( ( "%lu" ) ,  (  self1167 ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str358 (    struct StrConcat_349  self1206 ) {
    struct StrConcat_349  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str354 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str359 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str357 (    struct StrConcat_348  self1206 ) {
    struct StrConcat_348  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str358 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str354 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str360 (    int32_t  self1143 ) {
    ( ( printf ) ( ( "%d" ) ,  (  self1143 ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str356 (    struct StrConcat_347  self1206 ) {
    struct StrConcat_347  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str357 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str360 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str361 (    char  self1116 ) {
    ( ( printf ) ( ( "%c" ) ,  (  self1116 ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str355 (    struct StrConcat_346  self1206 ) {
    struct StrConcat_346  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str356 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str353 (    struct StrConcat_352  self1206 ) {
    struct StrConcat_352  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str354 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str355 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str350 (    struct StrConcat_351  self1206 ) {
    struct StrConcat_351  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str353 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   panic345 (    struct StrConcat_346  errmsg1383 ) {
    ( (  print_dash_str350 ) ( ( ( StrConcat_351_StrConcat ) ( ( ( StrConcat_352_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1383 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral2 ( 1 ) ) ) );
    return ( Unit_141_Unit );
}

static  uint32_t *   get_dash_ptr344 (    struct Array_62 *  arr1697 ,    size_t  i1700 ) {
    if ( ( (  cmp38 ( (  i1700 ) , (  from_dash_integral7 ( 0 ) ) ) == 0 ) || (  cmp38 ( (  i1700 ) , ( (size_t ) ( 4 ) ) ) != 0 ) ) ) {
        ( (  panic345 ) ( ( ( StrConcat_346_StrConcat ) ( ( ( StrConcat_347_StrConcat ) ( ( ( StrConcat_348_StrConcat ) ( ( ( StrConcat_349_StrConcat ) ( ( "Access to array at index " ) ,  (  i1700 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 4 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint32_t *  p1701 = ( ( (  cast_dash_ptr168 ) ( (  arr1697 ) ) ) );
    return ( (  offset_dash_ptr122 ) ( (  p1701 ) ,  ( (int64_t ) (  i1700 ) ) ) );
}

static  uint32_t   get343 (    struct Array_62 *  arr1704 ,    size_t  i1707 ) {
    return ( * ( (  get_dash_ptr344 ) ( (  arr1704 ) ,  (  i1707 ) ) ) );
}

static  struct Maybe_244   next342 (    struct SmolArrayIter_340 *  self1742 ) {
    if ( (  cmp38 ( ( ( * (  self1742 ) ) .f_cur ) , ( (size_t ) ( 4 ) ) ) != 0 ) ) {
        return ( (struct Maybe_244) { .tag = Maybe_244_None_t } );
    }
    uint32_t  e1744 = ( (  get343 ) ( ( & ( ( ( * (  self1742 ) ) .f_backing ) .f_arr ) ) ,  ( ( * (  self1742 ) ) .f_cur ) ) );
    (*  self1742 ) .f_cur = (  op_dash_add57 ( ( ( * (  self1742 ) ) .f_cur ) , (  from_dash_integral7 ( 1 ) ) ) );
    return ( ( Maybe_244_Just ) ( (  e1744 ) ) );
}

static  uint32_t   reduce339 (    struct SmolArray_61  iterable855 ,    uint32_t  base857 ,    uint32_t (*  fun859 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x860 = (  base857 );
    struct SmolArrayIter_340  it861 = ( (  into_dash_iter341 ) ( (  iterable855 ) ) );
    while ( ( true ) ) {
        struct Maybe_244  dref862 = ( (  next342 ) ( ( & (  it861 ) ) ) );
        if ( dref862.tag == Maybe_244_None_t ) {
            return (  x860 );
        }
        else {
            if ( dref862.tag == Maybe_244_Just_t ) {
                x860 = ( (  fun859 ) ( ( dref862 .stuff .Maybe_244_Just_s .field0 ) ,  (  x860 ) ) );
            }
        }
    }
    uint32_t  temp362;
    return (  temp362 );
}

struct SmolArrayIter_364 {
    struct SmolArray_64  f_backing;
    size_t  f_cur;
};

static  struct SmolArrayIter_364   into_dash_iter365 (    struct SmolArray_64  self1735 ) {
    return ( (struct SmolArrayIter_364) { .f_backing = (  self1735 ) , .f_cur = (  from_dash_integral7 ( 0 ) ) } );
}

static  uint32_t *   get_dash_ptr368 (    struct Array_65 *  arr1697 ,    size_t  i1700 ) {
    if ( ( (  cmp38 ( (  i1700 ) , (  from_dash_integral7 ( 0 ) ) ) == 0 ) || (  cmp38 ( (  i1700 ) , ( (size_t ) ( 5 ) ) ) != 0 ) ) ) {
        ( (  panic345 ) ( ( ( StrConcat_346_StrConcat ) ( ( ( StrConcat_347_StrConcat ) ( ( ( StrConcat_348_StrConcat ) ( ( ( StrConcat_349_StrConcat ) ( ( "Access to array at index " ) ,  (  i1700 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 5 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint32_t *  p1701 = ( ( (  cast_dash_ptr169 ) ( (  arr1697 ) ) ) );
    return ( (  offset_dash_ptr122 ) ( (  p1701 ) ,  ( (int64_t ) (  i1700 ) ) ) );
}

static  uint32_t   get367 (    struct Array_65 *  arr1704 ,    size_t  i1707 ) {
    return ( * ( (  get_dash_ptr368 ) ( (  arr1704 ) ,  (  i1707 ) ) ) );
}

static  struct Maybe_244   next366 (    struct SmolArrayIter_364 *  self1742 ) {
    if ( (  cmp38 ( ( ( * (  self1742 ) ) .f_cur ) , ( (size_t ) ( 5 ) ) ) != 0 ) ) {
        return ( (struct Maybe_244) { .tag = Maybe_244_None_t } );
    }
    uint32_t  e1744 = ( (  get367 ) ( ( & ( ( ( * (  self1742 ) ) .f_backing ) .f_arr ) ) ,  ( ( * (  self1742 ) ) .f_cur ) ) );
    (*  self1742 ) .f_cur = (  op_dash_add57 ( ( ( * (  self1742 ) ) .f_cur ) , (  from_dash_integral7 ( 1 ) ) ) );
    return ( ( Maybe_244_Just ) ( (  e1744 ) ) );
}

static  uint32_t   reduce363 (    struct SmolArray_64  iterable855 ,    uint32_t  base857 ,    uint32_t (*  fun859 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x860 = (  base857 );
    struct SmolArrayIter_364  it861 = ( (  into_dash_iter365 ) ( (  iterable855 ) ) );
    while ( ( true ) ) {
        struct Maybe_244  dref862 = ( (  next366 ) ( ( & (  it861 ) ) ) );
        if ( dref862.tag == Maybe_244_None_t ) {
            return (  x860 );
        }
        else {
            if ( dref862.tag == Maybe_244_Just_t ) {
                x860 = ( (  fun859 ) ( ( dref862 .stuff .Maybe_244_Just_s .field0 ) ,  (  x860 ) ) );
            }
        }
    }
    uint32_t  temp369;
    return (  temp369 );
}

struct SmolArrayIter_371 {
    struct SmolArray_67  f_backing;
    size_t  f_cur;
};

static  struct SmolArrayIter_371   into_dash_iter372 (    struct SmolArray_67  self1735 ) {
    return ( (struct SmolArrayIter_371) { .f_backing = (  self1735 ) , .f_cur = (  from_dash_integral7 ( 0 ) ) } );
}

static  uint32_t *   get_dash_ptr375 (    struct Array_68 *  arr1697 ,    size_t  i1700 ) {
    if ( ( (  cmp38 ( (  i1700 ) , (  from_dash_integral7 ( 0 ) ) ) == 0 ) || (  cmp38 ( (  i1700 ) , ( (size_t ) ( 1 ) ) ) != 0 ) ) ) {
        ( (  panic345 ) ( ( ( StrConcat_346_StrConcat ) ( ( ( StrConcat_347_StrConcat ) ( ( ( StrConcat_348_StrConcat ) ( ( ( StrConcat_349_StrConcat ) ( ( "Access to array at index " ) ,  (  i1700 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 1 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint32_t *  p1701 = ( ( (  cast_dash_ptr170 ) ( (  arr1697 ) ) ) );
    return ( (  offset_dash_ptr122 ) ( (  p1701 ) ,  ( (int64_t ) (  i1700 ) ) ) );
}

static  uint32_t   get374 (    struct Array_68 *  arr1704 ,    size_t  i1707 ) {
    return ( * ( (  get_dash_ptr375 ) ( (  arr1704 ) ,  (  i1707 ) ) ) );
}

static  struct Maybe_244   next373 (    struct SmolArrayIter_371 *  self1742 ) {
    if ( (  cmp38 ( ( ( * (  self1742 ) ) .f_cur ) , ( (size_t ) ( 1 ) ) ) != 0 ) ) {
        return ( (struct Maybe_244) { .tag = Maybe_244_None_t } );
    }
    uint32_t  e1744 = ( (  get374 ) ( ( & ( ( ( * (  self1742 ) ) .f_backing ) .f_arr ) ) ,  ( ( * (  self1742 ) ) .f_cur ) ) );
    (*  self1742 ) .f_cur = (  op_dash_add57 ( ( ( * (  self1742 ) ) .f_cur ) , (  from_dash_integral7 ( 1 ) ) ) );
    return ( ( Maybe_244_Just ) ( (  e1744 ) ) );
}

static  uint32_t   reduce370 (    struct SmolArray_67  iterable855 ,    uint32_t  base857 ,    uint32_t (*  fun859 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x860 = (  base857 );
    struct SmolArrayIter_371  it861 = ( (  into_dash_iter372 ) ( (  iterable855 ) ) );
    while ( ( true ) ) {
        struct Maybe_244  dref862 = ( (  next373 ) ( ( & (  it861 ) ) ) );
        if ( dref862.tag == Maybe_244_None_t ) {
            return (  x860 );
        }
        else {
            if ( dref862.tag == Maybe_244_Just_t ) {
                x860 = ( (  fun859 ) ( ( dref862 .stuff .Maybe_244_Just_s .field0 ) ,  (  x860 ) ) );
            }
        }
    }
    uint32_t  temp376;
    return (  temp376 );
}

static  size_t   reduce377 (    struct TakeWhile_293  iterable855 ,    size_t  base857 ,    size_t (*  fun859 )(    char  ,    size_t  ) ) {
    size_t  x860 = (  base857 );
    struct TakeWhile_293  it861 = ( (  into_dash_iter292 ) ( (  iterable855 ) ) );
    while ( ( true ) ) {
        struct Maybe_245  dref862 = ( (  next294 ) ( ( & (  it861 ) ) ) );
        if ( dref862.tag == Maybe_245_None_t ) {
            return (  x860 );
        }
        else {
            if ( dref862.tag == Maybe_245_Just_t ) {
                x860 = ( (  fun859 ) ( ( dref862 .stuff .Maybe_245_Just_s .field0 ) ,  (  x860 ) ) );
            }
        }
    }
    size_t  temp378;
    return (  temp378 );
}

static  struct Maybe_337   reduce379 (    struct TakeWhile_293  iterable855 ,    struct Maybe_337  base857 ,    struct Maybe_337 (*  fun859 )(    char  ,    struct Maybe_337  ) ) {
    struct Maybe_337  x860 = (  base857 );
    struct TakeWhile_293  it861 = ( (  into_dash_iter292 ) ( (  iterable855 ) ) );
    while ( ( true ) ) {
        struct Maybe_245  dref862 = ( (  next294 ) ( ( & (  it861 ) ) ) );
        if ( dref862.tag == Maybe_245_None_t ) {
            return (  x860 );
        }
        else {
            if ( dref862.tag == Maybe_245_Just_t ) {
                x860 = ( (  fun859 ) ( ( dref862 .stuff .Maybe_245_Just_s .field0 ) ,  (  x860 ) ) );
            }
        }
    }
    struct Maybe_337  temp380;
    return (  temp380 );
}

static  uint32_t   reduce381 (    struct Map_241  iterable855 ,    uint32_t  base857 ,    uint32_t (*  fun859 )(    uint32_t  ,    uint32_t  ) ) {
    uint32_t  x860 = (  base857 );
    struct Map_241  it861 = ( (  into_dash_iter240 ) ( (  iterable855 ) ) );
    while ( ( true ) ) {
        struct Maybe_244  dref862 = ( (  next243 ) ( ( & (  it861 ) ) ) );
        if ( dref862.tag == Maybe_244_None_t ) {
            return (  x860 );
        }
        else {
            if ( dref862.tag == Maybe_244_Just_t ) {
                x860 = ( (  fun859 ) ( ( dref862 .stuff .Maybe_244_Just_s .field0 ) ,  (  x860 ) ) );
            }
        }
    }
    uint32_t  temp382;
    return (  temp382 );
}

struct env384 {
    bool (*  fun888 )(    struct Tile_91  );
};

struct funenv384 {
    bool  (*fun) (  struct env384  ,    struct Tile_91  ,    bool  );
    struct env384 env;
};

static  bool   reduce383 (    struct FlattenIter_288  iterable855 ,    bool  base857 ,   struct funenv384  fun859 ) {
    bool  x860 = (  base857 );
    struct FlattenIter_288  it861 = ( (  into_dash_iter287 ) ( (  iterable855 ) ) );
    while ( ( true ) ) {
        struct Maybe_276  dref862 = ( (  next289 ) ( ( & (  it861 ) ) ) );
        if ( dref862.tag == Maybe_276_None_t ) {
            return (  x860 );
        }
        else {
            if ( dref862.tag == Maybe_276_Just_t ) {
                struct funenv384  temp385 = (  fun859 );
                x860 = ( temp385.fun ( temp385.env ,  ( dref862 .stuff .Maybe_276_Just_s .field0 ) ,  (  x860 ) ) );
            }
        }
    }
    bool  temp386;
    return (  temp386 );
}

struct env388 {
    ;
    int32_t  base966;
};

struct funenv388 {
    int32_t  (*fun) (  struct env388  ,    int32_t  ,    int32_t  );
    struct env388 env;
};

static  int32_t   reduce387 (    struct Range_250  iterable855 ,    int32_t  base857 ,   struct funenv388  fun859 ) {
    int32_t  x860 = (  base857 );
    struct RangeIter_252  it861 = ( (  into_dash_iter251 ) ( (  iterable855 ) ) );
    while ( ( true ) ) {
        struct Maybe_254  dref862 = ( (  next253 ) ( ( & (  it861 ) ) ) );
        if ( dref862.tag == Maybe_254_None_t ) {
            return (  x860 );
        }
        else {
            if ( dref862.tag == Maybe_254_Just_t ) {
                struct funenv388  temp389 = (  fun859 );
                x860 = ( temp389.fun ( temp389.env ,  ( dref862 .stuff .Maybe_254_Just_s .field0 ) ,  (  x860 ) ) );
            }
        }
    }
    int32_t  temp390;
    return (  temp390 );
}

static  size_t   reduce391 (    struct ConstStrIter_242  iterable855 ,    size_t  base857 ,    size_t (*  fun859 )(    char  ,    size_t  ) ) {
    size_t  x860 = (  base857 );
    struct ConstStrIter_242  it861 = ( (  into_dash_iter286 ) ( (  iterable855 ) ) );
    while ( ( true ) ) {
        struct Maybe_245  dref862 = ( (  next246 ) ( ( & (  it861 ) ) ) );
        if ( dref862.tag == Maybe_245_None_t ) {
            return (  x860 );
        }
        else {
            if ( dref862.tag == Maybe_245_Just_t ) {
                x860 = ( (  fun859 ) ( ( dref862 .stuff .Maybe_245_Just_s .field0 ) ,  (  x860 ) ) );
            }
        }
    }
    size_t  temp392;
    return (  temp392 );
}

static  size_t   lam394 (    char  dref867 ,    size_t  x869 ) {
    return (  op_dash_add57 ( (  x869 ) , (  from_dash_integral7 ( 1 ) ) ) );
}

static  size_t   count393 (    struct TakeWhile_293  it866 ) {
    return ( (  reduce377 ) ( (  it866 ) ,  (  from_dash_integral7 ( 0 ) ) ,  (  lam394 ) ) );
}

static  size_t   lam396 (    char  dref867 ,    size_t  x869 ) {
    return (  op_dash_add57 ( (  x869 ) , (  from_dash_integral7 ( 1 ) ) ) );
}

static  size_t   count395 (    struct ConstStrIter_242  it866 ) {
    return ( (  reduce391 ) ( (  it866 ) ,  (  from_dash_integral7 ( 0 ) ) ,  (  lam396 ) ) );
}

static  bool   lam384 (   struct env384 env ,    struct Tile_91  e890 ,    bool  x892 ) {
    return ( ( ( env.fun888 ) ( (  e890 ) ) ) && (  x892 ) );
}

static  bool   all397 (    struct FlattenIter_288  it886 ,    bool (*  fun888 )(    struct Tile_91  ) ) {
    struct env384 envinst384 = {
        .fun888 =  fun888 ,
    };
    return ( (  reduce383 ) ( (  it886 ) ,  ( true ) ,  ( (struct funenv384){ .fun = lam384, .env = envinst384 } ) ) );
}

static  struct Maybe_245   head398 (    struct ConstStrIter_242  it904 ) {
    struct ConstStrIter_242  temp399 = ( (  into_dash_iter286 ) ( (  it904 ) ) );
    return ( (  next246 ) ( ( &temp399 ) ) );
}

static  struct Maybe_245   head400 (    struct TakeWhile_293  it904 ) {
    struct TakeWhile_293  temp401 = ( (  into_dash_iter292 ) ( (  it904 ) ) );
    return ( (  next294 ) ( ( &temp401 ) ) );
}

struct IntStrIter_403 {
    int32_t  f_int;
    int32_t  f_len;
};

static  int32_t   lam388 (   struct env388 env ,    int32_t  item970 ,    int32_t  x972 ) {
    return (  op_dash_mul48 ( (  x972 ) , ( env.base966 ) ) );
}

static  int32_t   pow405 (    int32_t  base966 ,    int32_t  p968 ) {
    struct env388 envinst388 = {
        .base966 =  base966 ,
    };
    return ( (  reduce387 ) ( ( (  to249 ) ( (  from_dash_integral2 ( 0 ) ) ,  (  op_dash_sub47 ( (  p968 ) , (  from_dash_integral2 ( 1 ) ) ) ) ) ) ,  (  from_dash_integral2 ( 1 ) ) ,  ( (struct funenv388){ .fun = lam388, .env = envinst388 } ) ) );
}

static  struct Maybe_245   next404 (    struct IntStrIter_403 *  self1131 ) {
    if ( (  cmp39 ( ( ( * (  self1131 ) ) .f_len ) , (  from_dash_integral2 ( 0 ) ) ) != 2 ) ) {
        return ( (struct Maybe_245) { .tag = Maybe_245_None_t } );
    }
    int32_t  trim_dash_down1132 = ( (  pow405 ) ( (  from_dash_integral2 ( 10 ) ) ,  (  op_dash_sub47 ( ( ( * (  self1131 ) ) .f_len ) , (  from_dash_integral2 ( 1 ) ) ) ) ) );
    int32_t  upper1133 = (  op_dash_div49 ( ( ( * (  self1131 ) ) .f_int ) , (  trim_dash_down1132 ) ) );
    int32_t  upper_dash_mask1134 = (  op_dash_mul48 ( (  op_dash_div49 ( (  upper1133 ) , (  from_dash_integral2 ( 10 ) ) ) ) , (  from_dash_integral2 ( 10 ) ) ) );
    int32_t  digit1135 = (  op_dash_sub47 ( (  upper1133 ) , (  upper_dash_mask1134 ) ) );
    (*  self1131 ) .f_len = (  op_dash_sub47 ( ( ( * (  self1131 ) ) .f_len ) , (  from_dash_integral2 ( 1 ) ) ) );
    char  digit_dash_char1136 = ( (  cast157 ) ( (  op_dash_add46 ( (  digit1135 ) , (  from_dash_integral2 ( 48 ) ) ) ) ) );
    return ( ( Maybe_245_Just ) ( (  digit_dash_char1136 ) ) );
}

static  struct IntStrIter_403   into_dash_iter407 (    struct IntStrIter_403  self1128 ) {
    return (  self1128 );
}

static  struct Maybe_245   head402 (    struct IntStrIter_403  it904 ) {
    struct IntStrIter_403  temp406 = ( (  into_dash_iter407 ) ( (  it904 ) ) );
    return ( (  next404 ) ( ( &temp406 ) ) );
}

static  bool   null408 (    struct TakeWhile_293  it907 ) {
    struct Maybe_245  dref908 = ( (  head400 ) ( (  it907 ) ) );
    if ( dref908.tag == Maybe_245_None_t ) {
        return ( true );
    }
    else {
        if ( true ) {
            return ( false );
        }
    }
}

static  struct Maybe_245   lam321 (   struct env321 env ,    int32_t  dref945 ) {
    return ( (  next295 ) ( ( env.it942 ) ) );
}

static  enum Unit_141   drop_prime_409 (    struct Scanner_236 *  it942 ,    size_t  n944 ) {
    struct env321 envinst321 = {
        .it942 =  it942 ,
    };
    ( (  for_dash_each320 ) ( ( (  to249 ) ( (  from_dash_integral2 ( 1 ) ) ,  ( (  size_dash_i32228 ) ( (  n944 ) ) ) ) ) ,  ( (struct funenv321){ .fun = lam321, .env = envinst321 } ) ) );
    return ( Unit_141_Unit );
}

struct Tuple2_411 {
    int32_t  field0;
    int32_t  field1;
};

static struct Tuple2_411 Tuple2_411_Tuple2 (  int32_t  field0 ,  int32_t  field1 ) {
    return ( struct Tuple2_411 ) { .field0 = field0 ,  .field1 = field1 };
};

static  int32_t   fst410 (    struct Tuple2_411  dref1006 ) {
    return ( dref1006 .field0 );
}

struct Tuple2_413 {
    uint32_t  field0;
    uint32_t  field1;
};

static struct Tuple2_413 Tuple2_413_Tuple2 (  uint32_t  field0 ,  uint32_t  field1 ) {
    return ( struct Tuple2_413 ) { .field0 = field0 ,  .field1 = field1 };
};

static  uint32_t   fst412 (    struct Tuple2_413  dref1006 ) {
    return ( dref1006 .field0 );
}

static  int32_t   snd414 (    struct Tuple2_411  dref1009 ) {
    return ( dref1009 .field1 );
}

static  uint32_t   snd415 (    struct Tuple2_413  dref1009 ) {
    return ( dref1009 .field1 );
}

struct env417 {
    ;
    size_t  x2517;
};

struct funenv417 {
    struct Maybe_276  (*fun) (  struct env417  ,    struct Slice_90  );
    struct env417 env;
};

static  struct Maybe_276   and_dash_maybe416 (    struct Maybe_271  m1017 ,   struct funenv417  fun1019 ) {
    struct Maybe_271  dref1020 = (  m1017 );
    if ( dref1020.tag == Maybe_271_None_t ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    else {
        if ( dref1020.tag == Maybe_271_Just_t ) {
            struct funenv417  temp418 = (  fun1019 );
            return ( temp418.fun ( temp418.env ,  ( dref1020 .stuff .Maybe_271_Just_s .field0 ) ) );
        }
    }
}

static  uint32_t   mod419 (    uint32_t  l985 ,    uint32_t  d987 ) {
    uint32_t  r988 = (  op_dash_div54 ( (  l985 ) , (  d987 ) ) );
    uint32_t  m989 = (  op_dash_sub52 ( (  l985 ) , (  op_dash_mul53 ( (  r988 ) , (  d987 ) ) ) ) );
    if ( (  cmp40 ( (  m989 ) , (  from_dash_integral3 ( 0 ) ) ) == 0 ) ) {
        return (  op_dash_add51 ( (  d987 ) , (  m989 ) ) );
    } else {
        return (  m989 );
    }
}

static  int32_t   mod420 (    int32_t  l985 ,    int32_t  d987 ) {
    int32_t  r988 = (  op_dash_div49 ( (  l985 ) , (  d987 ) ) );
    int32_t  m989 = (  op_dash_sub47 ( (  l985 ) , (  op_dash_mul48 ( (  r988 ) , (  d987 ) ) ) ) );
    if ( (  cmp39 ( (  m989 ) , (  from_dash_integral2 ( 0 ) ) ) == 0 ) ) {
        return (  op_dash_add46 ( (  d987 ) , (  m989 ) ) );
    } else {
        return (  m989 );
    }
}

static  size_t   min421 (    size_t  l992 ,    size_t  r994 ) {
    if ( (  cmp38 ( (  l992 ) , (  r994 ) ) == 0 ) ) {
        return (  l992 );
    } else {
        return (  r994 );
    }
}

static  int32_t   min422 (    int32_t  l992 ,    int32_t  r994 ) {
    if ( (  cmp39 ( (  l992 ) , (  r994 ) ) == 0 ) ) {
        return (  l992 );
    } else {
        return (  r994 );
    }
}

static  struct ConstStrIter_242   chars423 (    const char*  self1113 ) {
    return ( (  into_dash_iter248 ) ( (  self1113 ) ) );
}

static  int32_t   count_dash_digits424 (    int32_t  self1139 ) {
    if ( (  eq8 ( (  self1139 ) , (  from_dash_integral2 ( 0 ) ) ) ) ) {
        return (  from_dash_integral2 ( 1 ) );
    }
    int32_t  digits1140 = (  from_dash_integral2 ( 0 ) );
    while ( (  cmp39 ( (  self1139 ) , (  from_dash_integral2 ( 0 ) ) ) == 2 ) ) {
        self1139 = (  op_dash_div49 ( (  self1139 ) , (  from_dash_integral2 ( 10 ) ) ) );
        digits1140 = (  op_dash_add46 ( (  digits1140 ) , (  from_dash_integral2 ( 1 ) ) ) );
    }
    return (  digits1140 );
}

static  struct IntStrIter_403   chars425 (    int32_t  self1146 ) {
    return ( (struct IntStrIter_403) { .f_int = (  self1146 ) , .f_len = ( (  count_dash_digits424 ) ( (  self1146 ) ) ) } );
}

static  enum Unit_141   print_dash_str426 (    uint32_t  self1149 ) {
    ( ( printf ) ( ( "%u" ) ,  (  self1149 ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str427 (    uint8_t  self1155 ) {
    ( ( printf ) ( ( "%d" ) ,  ( (  u8_dash_i32234 ) ( (  self1155 ) ) ) ) );
    return ( Unit_141_Unit );
}

struct StrConcat_430 {
    const char*  field0;
    const char*  field1;
};

static struct StrConcat_430 StrConcat_430_StrConcat (  const char*  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_430 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_429 {
    struct StrConcat_430  field0;
    char  field1;
};

static struct StrConcat_429 StrConcat_429_StrConcat (  struct StrConcat_430  field0 ,  char  field1 ) {
    return ( struct StrConcat_429 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_141   print_dash_str431 (    struct StrConcat_430  self1206 ) {
    struct StrConcat_430  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str354 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str354 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str428 (    struct StrConcat_429  self1206 ) {
    struct StrConcat_429  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str431 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

struct StrConcat_436 {
    struct StrConcat_348  field0;
    size_t  field1;
};

static struct StrConcat_436 StrConcat_436_StrConcat (  struct StrConcat_348  field0 ,  size_t  field1 ) {
    return ( struct StrConcat_436 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_435 {
    struct StrConcat_436  field0;
    char  field1;
};

static struct StrConcat_435 StrConcat_435_StrConcat (  struct StrConcat_436  field0 ,  char  field1 ) {
    return ( struct StrConcat_435 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_434 {
    const char*  field0;
    struct StrConcat_435  field1;
};

static struct StrConcat_434 StrConcat_434_StrConcat (  const char*  field0 ,  struct StrConcat_435  field1 ) {
    return ( struct StrConcat_434 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_433 {
    struct StrConcat_434  field0;
    char  field1;
};

static struct StrConcat_433 StrConcat_433_StrConcat (  struct StrConcat_434  field0 ,  char  field1 ) {
    return ( struct StrConcat_433 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_141   print_dash_str439 (    struct StrConcat_436  self1206 ) {
    struct StrConcat_436  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str357 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str359 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str438 (    struct StrConcat_435  self1206 ) {
    struct StrConcat_435  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str439 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str437 (    struct StrConcat_434  self1206 ) {
    struct StrConcat_434  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str354 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str438 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str432 (    struct StrConcat_433  self1206 ) {
    struct StrConcat_433  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str437 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

struct StrConcat_442 {
    char  field0;
    char  field1;
};

static struct StrConcat_442 StrConcat_442_StrConcat (  char  field0 ,  char  field1 ) {
    return ( struct StrConcat_442 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_441 {
    struct StrConcat_442  field0;
    const char*  field1;
};

static struct StrConcat_441 StrConcat_441_StrConcat (  struct StrConcat_442  field0 ,  const char*  field1 ) {
    return ( struct StrConcat_441 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_141   print_dash_str443 (    struct StrConcat_442  self1206 ) {
    struct StrConcat_442  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str361 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str440 (    struct StrConcat_441  self1206 ) {
    struct StrConcat_441  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str443 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str354 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

struct StrConcat_446 {
    const char*  field0;
    struct StrConcat_441  field1;
};

static struct StrConcat_446 StrConcat_446_StrConcat (  const char*  field0 ,  struct StrConcat_441  field1 ) {
    return ( struct StrConcat_446 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_445 {
    struct StrConcat_446  field0;
    char  field1;
};

static struct StrConcat_445 StrConcat_445_StrConcat (  struct StrConcat_446  field0 ,  char  field1 ) {
    return ( struct StrConcat_445 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_141   print_dash_str447 (    struct StrConcat_446  self1206 ) {
    struct StrConcat_446  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str354 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str440 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str444 (    struct StrConcat_445  self1206 ) {
    struct StrConcat_445  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str447 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

struct StrConcat_452 {
    const char*  field0;
    uint32_t  field1;
};

static struct StrConcat_452 StrConcat_452_StrConcat (  const char*  field0 ,  uint32_t  field1 ) {
    return ( struct StrConcat_452 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_451 {
    struct StrConcat_452  field0;
    char  field1;
};

static struct StrConcat_451 StrConcat_451_StrConcat (  struct StrConcat_452  field0 ,  char  field1 ) {
    return ( struct StrConcat_451 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_450 {
    struct StrConcat_451  field0;
    uint32_t  field1;
};

static struct StrConcat_450 StrConcat_450_StrConcat (  struct StrConcat_451  field0 ,  uint32_t  field1 ) {
    return ( struct StrConcat_450 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_449 {
    struct StrConcat_450  field0;
    char  field1;
};

static struct StrConcat_449 StrConcat_449_StrConcat (  struct StrConcat_450  field0 ,  char  field1 ) {
    return ( struct StrConcat_449 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_141   print_dash_str455 (    struct StrConcat_452  self1206 ) {
    struct StrConcat_452  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str354 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str426 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str454 (    struct StrConcat_451  self1206 ) {
    struct StrConcat_451  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str455 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str453 (    struct StrConcat_450  self1206 ) {
    struct StrConcat_450  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str454 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str426 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str448 (    struct StrConcat_449  self1206 ) {
    struct StrConcat_449  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str453 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

struct StrConcat_462 {
    const char*  field0;
    uint8_t  field1;
};

static struct StrConcat_462 StrConcat_462_StrConcat (  const char*  field0 ,  uint8_t  field1 ) {
    return ( struct StrConcat_462 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_461 {
    struct StrConcat_462  field0;
    char  field1;
};

static struct StrConcat_461 StrConcat_461_StrConcat (  struct StrConcat_462  field0 ,  char  field1 ) {
    return ( struct StrConcat_461 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_460 {
    struct StrConcat_461  field0;
    uint8_t  field1;
};

static struct StrConcat_460 StrConcat_460_StrConcat (  struct StrConcat_461  field0 ,  uint8_t  field1 ) {
    return ( struct StrConcat_460 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_459 {
    struct StrConcat_460  field0;
    char  field1;
};

static struct StrConcat_459 StrConcat_459_StrConcat (  struct StrConcat_460  field0 ,  char  field1 ) {
    return ( struct StrConcat_459 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_458 {
    struct StrConcat_459  field0;
    uint8_t  field1;
};

static struct StrConcat_458 StrConcat_458_StrConcat (  struct StrConcat_459  field0 ,  uint8_t  field1 ) {
    return ( struct StrConcat_458 ) { .field0 = field0 ,  .field1 = field1 };
};

struct StrConcat_457 {
    struct StrConcat_458  field0;
    char  field1;
};

static struct StrConcat_457 StrConcat_457_StrConcat (  struct StrConcat_458  field0 ,  char  field1 ) {
    return ( struct StrConcat_457 ) { .field0 = field0 ,  .field1 = field1 };
};

static  enum Unit_141   print_dash_str467 (    struct StrConcat_462  self1206 ) {
    struct StrConcat_462  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str354 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str427 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str466 (    struct StrConcat_461  self1206 ) {
    struct StrConcat_461  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str467 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str465 (    struct StrConcat_460  self1206 ) {
    struct StrConcat_460  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str466 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str427 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str464 (    struct StrConcat_459  self1206 ) {
    struct StrConcat_459  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str465 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str463 (    struct StrConcat_458  self1206 ) {
    struct StrConcat_458  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str464 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str427 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   print_dash_str456 (    struct StrConcat_457  self1206 ) {
    struct StrConcat_457  dref1207 = (  self1206 );
    if ( true ) {
        ( (  print_dash_str463 ) ( ( dref1207 .field0 ) ) );
        ( (  print_dash_str361 ) ( ( dref1207 .field1 ) ) );
    }
    return ( Unit_141_Unit );
}

static  struct TakeWhile_293   chars468 (    struct TakeWhile_293  self1322 ) {
    return (  self1322 );
}

static  int32_t   char_dash_i32469 (    char  c1349 ) {
    return ( (  cast_dash_on_dash_zeroed203 ) ( (  c1349 ) ) );
}

static  uint8_t   char_dash_u8470 (    char  c1352 ) {
    return ( (  cast155 ) ( (  c1352 ) ) );
}

static  char   i32_dash_char471 (    int32_t  i1355 ) {
    return ( (  cast157 ) ( (  i1355 ) ) );
}

static  bool   eq472 (    const char*  l1368 ,    const char*  r1370 ) {
    return (  eq8 ( ( ( strcmp ) ( (  l1368 ) ,  (  r1370 ) ) ) , (  from_dash_integral2 ( 0 ) ) ) );
}

static  enum Ordering_37   cmp473 (    char  l1373 ,    char  r1375 ) {
    return ( (  cmp39 ) ( ( (  char_dash_i32469 ) ( (  l1373 ) ) ) ,  ( (  char_dash_i32469 ) ( (  r1375 ) ) ) ) );
}

static  enum Unit_141   panic474 (    const char*  errmsg1383 ) {
    ( (  print_dash_str428 ) ( ( ( StrConcat_429_StrConcat ) ( ( ( StrConcat_430_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1383 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral2 ( 1 ) ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   panic475 (    struct StrConcat_435  errmsg1383 ) {
    ( (  print_dash_str432 ) ( ( ( StrConcat_433_StrConcat ) ( ( ( StrConcat_434_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1383 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral2 ( 1 ) ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   panic476 (    struct StrConcat_441  errmsg1383 ) {
    ( (  print_dash_str444 ) ( ( ( StrConcat_445_StrConcat ) ( ( ( StrConcat_446_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1383 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral2 ( 1 ) ) ) );
    return ( Unit_141_Unit );
}

static  enum MouseButton_106   panic_prime_477 (    const char*  errmsg1386 ) {
    ( (  print_dash_str428 ) ( ( ( StrConcat_429_StrConcat ) ( ( ( StrConcat_430_StrConcat ) ( ( "PANIC: " ) ,  (  errmsg1386 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "\n" ) ) ) ) ) ) );
    ( ( exit ) ( (  from_dash_integral2 ( 1 ) ) ) );
    return ( (  undefined105 ) ( ) );
}

static  int64_t   or_dash_fail478 (    struct Maybe_337  x1396 ,    const char*  errmsg1398 ) {
    struct Maybe_337  dref1399 = (  x1396 );
    if ( dref1399.tag == Maybe_337_None_t ) {
        ( (  panic474 ) ( (  errmsg1398 ) ) );
        return ( (  undefined87 ) ( ) );
    }
    else {
        if ( dref1399.tag == Maybe_337_Just_t ) {
            return ( dref1399 .stuff .Maybe_337_Just_s .field0 );
        }
    }
}

static  struct Slice_90   or_dash_fail479 (    struct Maybe_271  x1396 ,    struct StrConcat_435  errmsg1398 ) {
    struct Maybe_271  dref1399 = (  x1396 );
    if ( dref1399.tag == Maybe_271_None_t ) {
        ( (  panic475 ) ( (  errmsg1398 ) ) );
        return ( (  undefined89 ) ( ) );
    }
    else {
        if ( dref1399.tag == Maybe_271_Just_t ) {
            return ( dref1399 .stuff .Maybe_271_Just_s .field0 );
        }
    }
}

static  struct Tile_91   or_dash_fail480 (    struct Maybe_276  x1396 ,    struct StrConcat_435  errmsg1398 ) {
    struct Maybe_276  dref1399 = (  x1396 );
    if ( dref1399.tag == Maybe_276_None_t ) {
        ( (  panic475 ) ( (  errmsg1398 ) ) );
        return ( (  undefined93 ) ( ) );
    }
    else {
        if ( dref1399.tag == Maybe_276_Just_t ) {
            return ( dref1399 .stuff .Maybe_276_Just_s .field0 );
        }
    }
}

struct Maybe_482 {
    enum {
        Maybe_482_None_t,
        Maybe_482_Just_t,
    } tag;
    union {
        struct {
            struct Cell_15  field0;
        } Maybe_482_Just_s;
    } stuff;
};

static struct Maybe_482 Maybe_482_Just (  struct Cell_15  field0 ) {
    return ( struct Maybe_482 ) { .tag = Maybe_482_Just_t, .stuff = { .Maybe_482_Just_s = { .field0 = field0 } } };
};

static  struct Cell_15   or_dash_fail481 (    struct Maybe_482  x1396 ,    struct StrConcat_435  errmsg1398 ) {
    struct Maybe_482  dref1399 = (  x1396 );
    if ( dref1399.tag == Maybe_482_None_t ) {
        ( (  panic475 ) ( (  errmsg1398 ) ) );
        return ( (  undefined101 ) ( ) );
    }
    else {
        if ( dref1399.tag == Maybe_482_Just_t ) {
            return ( dref1399 .stuff .Maybe_482_Just_s .field0 );
        }
    }
}

static  char   or_dash_fail483 (    struct Maybe_245  x1396 ,    struct StrConcat_435  errmsg1398 ) {
    struct Maybe_245  dref1399 = (  x1396 );
    if ( dref1399.tag == Maybe_245_None_t ) {
        ( (  panic475 ) ( (  errmsg1398 ) ) );
        return ( (  undefined103 ) ( ) );
    }
    else {
        if ( dref1399.tag == Maybe_245_Just_t ) {
            return ( dref1399 .stuff .Maybe_245_Just_s .field0 );
        }
    }
}

struct Maybe_485 {
    enum {
        Maybe_485_None_t,
        Maybe_485_Just_t,
    } tag;
    union {
        struct {
            uint8_t  field0;
        } Maybe_485_Just_s;
    } stuff;
};

static struct Maybe_485 Maybe_485_Just (  uint8_t  field0 ) {
    return ( struct Maybe_485 ) { .tag = Maybe_485_Just_t, .stuff = { .Maybe_485_Just_s = { .field0 = field0 } } };
};

static  uint8_t   or_dash_fail484 (    struct Maybe_485  x1396 ,    struct StrConcat_441  errmsg1398 ) {
    struct Maybe_485  dref1399 = (  x1396 );
    if ( dref1399.tag == Maybe_485_None_t ) {
        ( (  panic476 ) ( (  errmsg1398 ) ) );
        return ( (  undefined108 ) ( ) );
    }
    else {
        if ( dref1399.tag == Maybe_485_Just_t ) {
            return ( dref1399 .stuff .Maybe_485_Just_s .field0 );
        }
    }
}

struct Maybe_487 {
    enum {
        Maybe_487_None_t,
        Maybe_487_Just_t,
    } tag;
    union {
        struct {
            struct Cell_15 *  field0;
        } Maybe_487_Just_s;
    } stuff;
};

static struct Maybe_487 Maybe_487_Just (  struct Cell_15 *  field0 ) {
    return ( struct Maybe_487 ) { .tag = Maybe_487_Just_t, .stuff = { .Maybe_487_Just_s = { .field0 = field0 } } };
};

static  struct Cell_15 *   or_dash_fail486 (    struct Maybe_487  x1396 ,    const char*  errmsg1398 ) {
    struct Maybe_487  dref1399 = (  x1396 );
    if ( dref1399.tag == Maybe_487_None_t ) {
        ( (  panic474 ) ( (  errmsg1398 ) ) );
        return ( (  undefined110 ) ( ) );
    }
    else {
        if ( dref1399.tag == Maybe_487_Just_t ) {
            return ( dref1399 .stuff .Maybe_487_Just_s .field0 );
        }
    }
}

static  char   or_dash_fail488 (    struct Maybe_245  x1396 ,    const char*  errmsg1398 ) {
    struct Maybe_245  dref1399 = (  x1396 );
    if ( dref1399.tag == Maybe_245_None_t ) {
        ( (  panic474 ) ( (  errmsg1398 ) ) );
        return ( (  undefined103 ) ( ) );
    }
    else {
        if ( dref1399.tag == Maybe_245_Just_t ) {
            return ( dref1399 .stuff .Maybe_245_Just_s .field0 );
        }
    }
}

static  struct Tile_91   or_dash_else489 (    struct Maybe_276  self1403 ,    struct Tile_91  alt1405 ) {
    struct Maybe_276  dref1406 = (  self1403 );
    if ( dref1406.tag == Maybe_276_None_t ) {
        return (  alt1405 );
    }
    else {
        if ( dref1406.tag == Maybe_276_Just_t ) {
            return ( dref1406 .stuff .Maybe_276_Just_s .field0 );
        }
    }
}

static  struct Tile_91 *   get_dash_ptr490 (    struct Slice_90  slice1429 ,    size_t  i1431 ) {
    if ( ( (  cmp38 ( (  i1431 ) , (  from_dash_integral7 ( 0 ) ) ) == 0 ) || (  cmp38 ( (  i1431 ) , ( (  slice1429 ) .f_count ) ) != 0 ) ) ) {
        ( (  panic475 ) ( ( ( StrConcat_435_StrConcat ) ( ( ( StrConcat_436_StrConcat ) ( ( ( StrConcat_348_StrConcat ) ( ( ( StrConcat_349_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1431 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1429 ) .f_count ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ")" ) ) ) ) ) ) );
    }
    struct Tile_91 *  elem_dash_ptr1432 = ( (  offset_dash_ptr118 ) ( ( (  slice1429 ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  i1431 ) ) ) ) );
    return (  elem_dash_ptr1432 );
}

static  struct Cell_15 *   get_dash_ptr491 (    struct Slice_313  slice1429 ,    size_t  i1431 ) {
    if ( ( (  cmp38 ( (  i1431 ) , (  from_dash_integral7 ( 0 ) ) ) == 0 ) || (  cmp38 ( (  i1431 ) , ( (  slice1429 ) .f_count ) ) != 0 ) ) ) {
        ( (  panic475 ) ( ( ( StrConcat_435_StrConcat ) ( ( ( StrConcat_436_StrConcat ) ( ( ( StrConcat_348_StrConcat ) ( ( ( StrConcat_349_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1431 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1429 ) .f_count ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ")" ) ) ) ) ) ) );
    }
    struct Cell_15 *  elem_dash_ptr1432 = ( (  offset_dash_ptr124 ) ( ( (  slice1429 ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  i1431 ) ) ) ) );
    return (  elem_dash_ptr1432 );
}

static  struct Maybe_271   try_dash_get492 (    struct Slice_262  slice1435 ,    size_t  i1437 ) {
    if ( ( (  cmp38 ( (  i1437 ) , (  from_dash_integral7 ( 0 ) ) ) == 0 ) || (  cmp38 ( (  i1437 ) , ( (  slice1435 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_271) { .tag = Maybe_271_None_t } );
    }
    struct Slice_90 *  elem_dash_ptr1438 = ( (  offset_dash_ptr116 ) ( ( (  slice1435 ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  i1437 ) ) ) ) );
    return ( ( Maybe_271_Just ) ( ( * (  elem_dash_ptr1438 ) ) ) );
}

static  struct Maybe_276   try_dash_get493 (    struct Slice_90  slice1435 ,    size_t  i1437 ) {
    if ( ( (  cmp38 ( (  i1437 ) , (  from_dash_integral7 ( 0 ) ) ) == 0 ) || (  cmp38 ( (  i1437 ) , ( (  slice1435 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_276) { .tag = Maybe_276_None_t } );
    }
    struct Tile_91 *  elem_dash_ptr1438 = ( (  offset_dash_ptr118 ) ( ( (  slice1435 ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  i1437 ) ) ) ) );
    return ( ( Maybe_276_Just ) ( ( * (  elem_dash_ptr1438 ) ) ) );
}

static  struct Maybe_482   try_dash_get494 (    struct Slice_313  slice1435 ,    size_t  i1437 ) {
    if ( ( (  cmp38 ( (  i1437 ) , (  from_dash_integral7 ( 0 ) ) ) == 0 ) || (  cmp38 ( (  i1437 ) , ( (  slice1435 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_482) { .tag = Maybe_482_None_t } );
    }
    struct Cell_15 *  elem_dash_ptr1438 = ( (  offset_dash_ptr124 ) ( ( (  slice1435 ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  i1437 ) ) ) ) );
    return ( ( Maybe_482_Just ) ( ( * (  elem_dash_ptr1438 ) ) ) );
}

static  struct Maybe_245   try_dash_get495 (    struct Slice_238  slice1435 ,    size_t  i1437 ) {
    if ( ( (  cmp38 ( (  i1437 ) , (  from_dash_integral7 ( 0 ) ) ) == 0 ) || (  cmp38 ( (  i1437 ) , ( (  slice1435 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Maybe_245) { .tag = Maybe_245_None_t } );
    }
    char *  elem_dash_ptr1438 = ( (  offset_dash_ptr114 ) ( ( (  slice1435 ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  i1437 ) ) ) ) );
    return ( ( Maybe_245_Just ) ( ( * (  elem_dash_ptr1438 ) ) ) );
}

static  struct Slice_90   get496 (    struct Slice_262  slice1441 ,    size_t  i1443 ) {
    return ( (  or_dash_fail479 ) ( ( (  try_dash_get492 ) ( (  slice1441 ) ,  (  i1443 ) ) ) ,  ( ( StrConcat_435_StrConcat ) ( ( ( StrConcat_436_StrConcat ) ( ( ( StrConcat_348_StrConcat ) ( ( ( StrConcat_349_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1443 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1441 ) .f_count ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ")" ) ) ) ) ) ) );
}

static  struct Tile_91   get497 (    struct Slice_90  slice1441 ,    size_t  i1443 ) {
    return ( (  or_dash_fail480 ) ( ( (  try_dash_get493 ) ( (  slice1441 ) ,  (  i1443 ) ) ) ,  ( ( StrConcat_435_StrConcat ) ( ( ( StrConcat_436_StrConcat ) ( ( ( StrConcat_348_StrConcat ) ( ( ( StrConcat_349_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1443 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1441 ) .f_count ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ")" ) ) ) ) ) ) );
}

static  struct Cell_15   get498 (    struct Slice_313  slice1441 ,    size_t  i1443 ) {
    return ( (  or_dash_fail481 ) ( ( (  try_dash_get494 ) ( (  slice1441 ) ,  (  i1443 ) ) ) ,  ( ( StrConcat_435_StrConcat ) ( ( ( StrConcat_436_StrConcat ) ( ( ( StrConcat_348_StrConcat ) ( ( ( StrConcat_349_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1443 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1441 ) .f_count ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ")" ) ) ) ) ) ) );
}

static  char   get499 (    struct Slice_238  slice1441 ,    size_t  i1443 ) {
    return ( (  or_dash_fail483 ) ( ( (  try_dash_get495 ) ( (  slice1441 ) ,  (  i1443 ) ) ) ,  ( ( StrConcat_435_StrConcat ) ( ( ( StrConcat_436_StrConcat ) ( ( ( StrConcat_348_StrConcat ) ( ( ( StrConcat_349_StrConcat ) ( ( "Access to slice at index " ) ,  (  i1443 ) ) ) ,  ( ". (max: " ) ) ) ,  ( (  slice1441 ) .f_count ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ")" ) ) ) ) ) ) );
}

static  enum Unit_141   set500 (    struct Slice_90  slice1446 ,    size_t  i1448 ,    struct Tile_91  x1450 ) {
    struct Tile_91 *  ep1451 = ( (  get_dash_ptr490 ) ( (  slice1446 ) ,  (  i1448 ) ) );
    (*  ep1451 ) = (  x1450 );
    return ( Unit_141_Unit );
}

static  enum Unit_141   set501 (    struct Slice_313  slice1446 ,    size_t  i1448 ,    struct Cell_15  x1450 ) {
    struct Cell_15 *  ep1451 = ( (  get_dash_ptr491 ) ( (  slice1446 ) ,  (  i1448 ) ) );
    (*  ep1451 ) = (  x1450 );
    return ( Unit_141_Unit );
}

struct Slice_503 {
    const char* *  f_ptr;
    size_t  f_count;
};

static  struct Slice_503   subslice502 (    struct Slice_503  slice1454 ,    size_t  from1456 ,    size_t  to1458 ) {
    const char* *  begin_dash_ptr1459 = ( (  offset_dash_ptr112 ) ( ( (  slice1454 ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  from1456 ) ) ) ) );
    if ( ( (  cmp38 ( (  from1456 ) , (  to1458 ) ) != 0 ) || (  cmp38 ( (  from1456 ) , ( (  slice1454 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Slice_503) { .f_ptr = (  begin_dash_ptr1459 ) , .f_count = (  from_dash_integral7 ( 0 ) ) } );
    }
    size_t  count1460 = (  op_dash_sub58 ( ( (  min421 ) ( (  to1458 ) ,  ( (  slice1454 ) .f_count ) ) ) , (  from1456 ) ) );
    return ( (struct Slice_503) { .f_ptr = (  begin_dash_ptr1459 ) , .f_count = (  count1460 ) } );
}

static  struct Slice_238   subslice504 (    struct Slice_238  slice1454 ,    size_t  from1456 ,    size_t  to1458 ) {
    char *  begin_dash_ptr1459 = ( (  offset_dash_ptr114 ) ( ( (  slice1454 ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  from1456 ) ) ) ) );
    if ( ( (  cmp38 ( (  from1456 ) , (  to1458 ) ) != 0 ) || (  cmp38 ( (  from1456 ) , ( (  slice1454 ) .f_count ) ) != 0 ) ) ) {
        return ( (struct Slice_238) { .f_ptr = (  begin_dash_ptr1459 ) , .f_count = (  from_dash_integral7 ( 0 ) ) } );
    }
    size_t  count1460 = (  op_dash_sub58 ( ( (  min421 ) ( (  to1458 ) ,  ( (  slice1454 ) .f_count ) ) ) , (  from1456 ) ) );
    return ( (struct Slice_238) { .f_ptr = (  begin_dash_ptr1459 ) , .f_count = (  count1460 ) } );
}

static  struct SliceIter_237   into_dash_iter505 (    struct Slice_238  self1494 ) {
    return ( (struct SliceIter_237) { .f_slice = (  self1494 ) , .f_current_dash_offset = (  from_dash_integral7 ( 0 ) ) } );
}

struct SliceAddressIter_507 {
    struct Slice_262  f_slice;
    size_t  f_current_dash_offset;
};

static  struct SliceAddressIter_507   addresses506 (    struct Slice_262  slice1512 ) {
    return ( (struct SliceAddressIter_507) { .f_slice = (  slice1512 ) , .f_current_dash_offset = (  from_dash_integral7 ( 0 ) ) } );
}

static  struct SliceAddressIter_507   into_dash_iter508 (    struct SliceAddressIter_507  self1515 ) {
    return (  self1515 );
}

struct Maybe_510 {
    enum {
        Maybe_510_None_t,
        Maybe_510_Just_t,
    } tag;
    union {
        struct {
            struct Slice_90 *  field0;
        } Maybe_510_Just_s;
    } stuff;
};

static struct Maybe_510 Maybe_510_Just (  struct Slice_90 *  field0 ) {
    return ( struct Maybe_510 ) { .tag = Maybe_510_Just_t, .stuff = { .Maybe_510_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_510   next509 (    struct SliceAddressIter_507 *  self1518 ) {
    size_t  off1519 = ( ( * (  self1518 ) ) .f_current_dash_offset );
    if ( (  cmp38 ( (  op_dash_add57 ( (  off1519 ) , (  from_dash_integral7 ( 1 ) ) ) ) , ( ( ( * (  self1518 ) ) .f_slice ) .f_count ) ) == 2 ) ) {
        return ( (struct Maybe_510) { .tag = Maybe_510_None_t } );
    }
    struct Slice_90 *  elem1520 = ( (  offset_dash_ptr116 ) ( ( ( ( * (  self1518 ) ) .f_slice ) .f_ptr ) ,  ( (  size_dash_i64222 ) ( (  off1519 ) ) ) ) );
    (*  self1518 ) .f_current_dash_offset = (  op_dash_add57 ( (  off1519 ) , (  from_dash_integral7 ( 1 ) ) ) );
    return ( ( Maybe_510_Just ) ( (  elem1520 ) ) );
}

static  struct Slice_90   elem_dash_get511 (    struct Slice_262  self1539 ,    size_t  idx1541 ) {
    return ( (  get496 ) ( (  self1539 ) ,  (  idx1541 ) ) );
}

static  struct Tile_91   elem_dash_get512 (    struct Slice_90  self1539 ,    size_t  idx1541 ) {
    return ( (  get497 ) ( (  self1539 ) ,  (  idx1541 ) ) );
}

static  struct Cell_15   elem_dash_get513 (    struct Slice_313  self1539 ,    size_t  idx1541 ) {
    return ( (  get498 ) ( (  self1539 ) ,  (  idx1541 ) ) );
}

static  char   elem_dash_get514 (    struct Slice_238  self1539 ,    size_t  idx1541 ) {
    return ( (  get499 ) ( (  self1539 ) ,  (  idx1541 ) ) );
}

struct ListSpread_516 {
    enum {
        ListSpread_516_NoSpread_t,
        ListSpread_516_UnassignedSpread_t,
        ListSpread_516_AssignedSpread_t,
    } tag;
    union {
        struct {
            struct Slice_503 *  field0;
        } ListSpread_516_AssignedSpread_s;
    } stuff;
};

static struct ListSpread_516 ListSpread_516_AssignedSpread (  struct Slice_503 *  field0 ) {
    return ( struct ListSpread_516 ) { .tag = ListSpread_516_AssignedSpread_t, .stuff = { .ListSpread_516_AssignedSpread_s = { .field0 = field0 } } };
};

static  bool   deconstruct515 (    struct Slice_503  self1550 ,    const char* * *  lp1552 ,    size_t  lc1554 ,    struct ListSpread_516  spread1556 ,    const char* * *  rp1558 ,    size_t  rc1560 ) {
    if ( (  cmp38 ( (  lc1554 ) , (  from_dash_integral7 ( 0 ) ) ) == 2 ) ) {
        if ( (  cmp38 ( (  lc1554 ) , ( (  self1550 ) .f_count ) ) == 2 ) ) {
            return ( false );
        }
        (*  lp1552 ) = ( (  self1550 ) .f_ptr );
    }
    if ( (  cmp38 ( (  rc1560 ) , (  from_dash_integral7 ( 0 ) ) ) == 2 ) ) {
        if ( (  cmp38 ( (  op_dash_add57 ( (  rc1560 ) , (  lc1554 ) ) ) , ( (  self1550 ) .f_count ) ) == 2 ) ) {
            return ( false );
        }
        struct Slice_503  cut1561 = ( (  subslice502 ) ( (  self1550 ) ,  (  op_dash_sub58 ( ( (  self1550 ) .f_count ) , (  rc1560 ) ) ) ,  ( (  self1550 ) .f_count ) ) );
        (*  rp1558 ) = ( (  cut1561 ) .f_ptr );
    }
    struct ListSpread_516  dref1562 = (  spread1556 );
    if ( dref1562.tag == ListSpread_516_NoSpread_t ) {
        return (  eq12 ( (  op_dash_add57 ( (  lc1554 ) , (  rc1560 ) ) ) , ( (  self1550 ) .f_count ) ) );
    }
    else {
        if ( dref1562.tag == ListSpread_516_UnassignedSpread_t ) {
            return ( true );
        }
        else {
            if ( dref1562.tag == ListSpread_516_AssignedSpread_t ) {
                (* dref1562 .stuff .ListSpread_516_AssignedSpread_s .field0 ) = ( (  subslice502 ) ( (  self1550 ) ,  (  lc1554 ) ,  (  op_dash_sub58 ( ( (  self1550 ) .f_count ) , (  rc1560 ) ) ) ) );
                return ( true );
            }
        }
    }
}

static  enum Unit_141   lam307 (   struct env307 env ,    int32_t  i1581 ) {
    struct funenv308  temp518 = ( env.fun1579 );
    return ( (  set500 ) ( ( env.s1577 ) ,  ( (  i32_dash_size225 ) ( (  i1581 ) ) ) ,  ( temp518.fun ( temp518.env ,  (  elem_dash_get512 ( ( env.s1577 ) , ( (  i32_dash_size225 ) ( (  i1581 ) ) ) ) ) ) ) ) );
}

static  enum Unit_141   map517 (    struct Slice_90  s1577 ,   struct funenv308  fun1579 ) {
    struct env307 envinst307 = {
        .s1577 =  s1577 ,
        .fun1579 =  fun1579 ,
    };
    ( (  for_dash_each306 ) ( ( (  to249 ) ( (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_i32228 ) ( (  op_dash_sub58 ( ( (  s1577 ) .f_count ) , (  from_dash_integral7 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv307){ .fun = lam307, .env = envinst307 } ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   lam312 (   struct env312 env ,    int32_t  i1581 ) {
    return ( (  set501 ) ( ( env.s1577 ) ,  ( (  i32_dash_size225 ) ( (  i1581 ) ) ) ,  ( ( env.fun1579 ) ( (  elem_dash_get513 ( ( env.s1577 ) , ( (  i32_dash_size225 ) ( (  i1581 ) ) ) ) ) ) ) ) );
}

static  enum Unit_141   map519 (    struct Slice_313  s1577 ,    struct Cell_15 (*  fun1579 )(    struct Cell_15  ) ) {
    struct env312 envinst312 = {
        .s1577 =  s1577 ,
        .fun1579 =  fun1579 ,
    };
    ( (  for_dash_each311 ) ( ( (  to249 ) ( (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_i32228 ) ( (  op_dash_sub58 ( ( (  s1577 ) .f_count ) , (  from_dash_integral7 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv312){ .fun = lam312, .env = envinst312 } ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   lam317 (   struct env317 env ,    int32_t  i1581 ) {
    return ( (  set501 ) ( ( env.s1577 ) ,  ( (  i32_dash_size225 ) ( (  i1581 ) ) ) ,  ( ( env.fun1579 ) ( (  elem_dash_get513 ( ( env.s1577 ) , ( (  i32_dash_size225 ) ( (  i1581 ) ) ) ) ) ) ) ) );
}

static  enum Unit_141   map520 (    struct Slice_313  s1577 ,    struct Cell_15 (*  fun1579 )(    struct Cell_15  ) ) {
    struct env317 envinst317 = {
        .s1577 =  s1577 ,
        .fun1579 =  fun1579 ,
    };
    ( (  for_dash_each316 ) ( ( (  to249 ) ( (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_i32228 ) ( (  op_dash_sub58 ( ( (  s1577 ) .f_count ) , (  from_dash_integral7 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv317){ .fun = lam317, .env = envinst317 } ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   lam325 (   struct env325 env ,    int32_t  i1581 ) {
    return ( (  set501 ) ( ( env.s1577 ) ,  ( (  i32_dash_size225 ) ( (  i1581 ) ) ) ,  ( ( env.fun1579 ) ( (  elem_dash_get513 ( ( env.s1577 ) , ( (  i32_dash_size225 ) ( (  i1581 ) ) ) ) ) ) ) ) );
}

static  enum Unit_141   map521 (    struct Slice_313  s1577 ,    struct Cell_15 (*  fun1579 )(    struct Cell_15  ) ) {
    struct env325 envinst325 = {
        .s1577 =  s1577 ,
        .fun1579 =  fun1579 ,
    };
    ( (  for_dash_each324 ) ( ( (  to249 ) ( (  from_dash_integral2 ( 0 ) ) ,  ( (  size_dash_i32228 ) ( (  op_dash_sub58 ( ( (  s1577 ) .f_count ) , (  from_dash_integral7 ( 1 ) ) ) ) ) ) ) ) ,  ( (struct funenv325){ .fun = lam325, .env = envinst325 } ) ) );
    return ( Unit_141_Unit );
}

static  enum CAllocator_331   idc522 (  ) {
    return ( CAllocator_331_CAllocator );
}

static  struct Slice_262   allocate523 (    enum CAllocator_331  dref1608 ,    size_t  count1610 ) {
    if (!(  dref1608 == CAllocator_331_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    size_t  size1611 = ( ( ( (  get_dash_typesize126 ) ( ) ) ) .f_size );
    struct Slice_90 *  ptr1612 = ( (  cast_dash_ptr162 ) ( ( ( malloc ) ( (  op_dash_mul59 ( (  size1611 ) , (  count1610 ) ) ) ) ) ) );
    return ( (struct Slice_262) { .f_ptr = (  ptr1612 ) , .f_count = (  count1610 ) } );
}

static  struct Slice_90   allocate524 (    enum CAllocator_331  dref1608 ,    size_t  count1610 ) {
    if (!(  dref1608 == CAllocator_331_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    size_t  size1611 = ( ( ( (  get_dash_typesize129 ) ( ) ) ) .f_size );
    struct Tile_91 *  ptr1612 = ( (  cast_dash_ptr163 ) ( ( ( malloc ) ( (  op_dash_mul59 ( (  size1611 ) , (  count1610 ) ) ) ) ) ) );
    return ( (struct Slice_90) { .f_ptr = (  ptr1612 ) , .f_count = (  count1610 ) } );
}

static  struct Slice_313   allocate525 (    enum CAllocator_331  dref1608 ,    size_t  count1610 ) {
    if (!(  dref1608 == CAllocator_331_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    size_t  size1611 = ( ( ( (  get_dash_typesize132 ) ( ) ) ) .f_size );
    struct Cell_15 *  ptr1612 = ( (  cast_dash_ptr174 ) ( ( ( malloc ) ( (  op_dash_mul59 ( (  size1611 ) , (  count1610 ) ) ) ) ) ) );
    return ( (struct Slice_313) { .f_ptr = (  ptr1612 ) , .f_count = (  count1610 ) } );
}

static  enum Unit_141   free526 (    enum CAllocator_331  dref1614 ,    struct Slice_313  slice1616 ) {
    if (!(  dref1614 == CAllocator_331_CAllocator )) {
        printf("%s\n", "pattern not matched to enter function");
        exit ( 1 );
    }
    ( ( free ) ( ( (  cast_dash_ptr182 ) ( ( (  slice1616 ) .f_ptr ) ) ) ) );
    return ( Unit_141_Unit );
}

static  struct Tile_91   lam308 (   struct env308 env ,    struct Tile_91  dref1625 ) {
    return ( env.x1623 );
}

static  struct Slice_90   default527 (    enum CAllocator_331  al1619 ,    size_t  count1621 ,    struct Tile_91  x1623 ) {
    struct Slice_90  s1624 = ( (  allocate524 ) ( (  al1619 ) ,  (  count1621 ) ) );
    struct env308 envinst308 = {
        .x1623 =  x1623 ,
    };
    ( (  map517 ) ( (  s1624 ) ,  ( (struct funenv308){ .fun = lam308, .env = envinst308 } ) ) );
    return (  s1624 );
}

struct DynStr_529 {
    struct Slice_238  f_contents;
};

static  struct SliceIter_237   chars528 (    struct DynStr_529  self1650 ) {
    return ( (  into_dash_iter505 ) ( ( (  self1650 ) .f_contents ) ) );
}

static  struct DynStr_529   substr530 (    struct DynStr_529  s1656 ,    size_t  from1658 ,    size_t  to1660 ) {
    return ( (struct DynStr_529) { .f_contents = ( (  subslice504 ) ( ( (  s1656 ) .f_contents ) ,  (  from1658 ) ,  (  to1660 ) ) ) } );
}

static  uint8_t *   get_dash_ptr531 (    struct Array_97 *  arr1697 ,    size_t  i1700 ) {
    if ( ( (  cmp38 ( (  i1700 ) , (  from_dash_integral7 ( 0 ) ) ) == 0 ) || (  cmp38 ( (  i1700 ) , ( (size_t ) ( 32 ) ) ) != 0 ) ) ) {
        ( (  panic345 ) ( ( ( StrConcat_346_StrConcat ) ( ( ( StrConcat_347_StrConcat ) ( ( ( StrConcat_348_StrConcat ) ( ( ( StrConcat_349_StrConcat ) ( ( "Access to array at index " ) ,  (  i1700 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 32 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ")" ) ) ) ) ) ) );
    }
    uint8_t *  p1701 = ( ( (  cast_dash_ptr166 ) ( (  arr1697 ) ) ) );
    return ( (  offset_dash_ptr120 ) ( (  p1701 ) ,  ( (int64_t ) (  i1700 ) ) ) );
}

static  char *   get_dash_ptr532 (    struct Array_145 *  arr1697 ,    size_t  i1700 ) {
    if ( ( (  cmp38 ( (  i1700 ) , (  from_dash_integral7 ( 0 ) ) ) == 0 ) || (  cmp38 ( (  i1700 ) , ( (size_t ) ( 32 ) ) ) != 0 ) ) ) {
        ( (  panic345 ) ( ( ( StrConcat_346_StrConcat ) ( ( ( StrConcat_347_StrConcat ) ( ( ( StrConcat_348_StrConcat ) ( ( ( StrConcat_349_StrConcat ) ( ( "Access to array at index " ) ,  (  i1700 ) ) ) ,  ( ". (max: " ) ) ) ,  ( 32 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ")" ) ) ) ) ) ) );
    }
    char *  p1701 = ( ( (  cast_dash_ptr178 ) ( (  arr1697 ) ) ) );
    return ( (  offset_dash_ptr114 ) ( (  p1701 ) ,  ( (int64_t ) (  i1700 ) ) ) );
}

static  enum Unit_141   set533 (    struct Array_97 *  arr1710 ,    size_t  i1713 ,    uint8_t  e1715 ) {
    uint8_t *  p1716 = ( (  get_dash_ptr531 ) ( (  arr1710 ) ,  (  i1713 ) ) );
    (*  p1716 ) = (  e1715 );
    return ( Unit_141_Unit );
}

static  enum Unit_141   set534 (    struct Array_145 *  arr1710 ,    size_t  i1713 ,    char  e1715 ) {
    char *  p1716 = ( (  get_dash_ptr532 ) ( (  arr1710 ) ,  (  i1713 ) ) );
    (*  p1716 ) = (  e1715 );
    return ( Unit_141_Unit );
}

static  struct Slice_238   as_dash_slice535 (    struct Array_145 *  arr1719 ) {
    return ( (struct Slice_238) { .f_ptr = ( (  cast158 ) ( (  arr1719 ) ) ) , .f_count = ( (size_t ) ( 32 ) ) } );
}

static  bool   is_dash_digit536 (    char  c1828 ) {
    return ( (  cmp39 ( ( (  char_dash_i32469 ) ( (  c1828 ) ) ) , ( (  char_dash_i32469 ) ( ( (  from_dash_charlike0 ) ( ( "0" ) ) ) ) ) ) != 0 ) && (  cmp39 ( ( (  char_dash_i32469 ) ( (  c1828 ) ) ) , ( (  char_dash_i32469 ) ( ( (  from_dash_charlike0 ) ( ( "9" ) ) ) ) ) ) != 2 ) );
}

static  struct Maybe_254   parse_dash_digit537 (    char  c1831 ) {
    if ( ( (  is_dash_digit536 ) ( (  c1831 ) ) ) ) {
        return ( ( Maybe_254_Just ) ( (  op_dash_sub47 ( ( (  char_dash_i32469 ) ( (  c1831 ) ) ) , ( (  char_dash_i32469 ) ( ( (  from_dash_charlike0 ) ( ( "0" ) ) ) ) ) ) ) ) );
    } else {
        return ( (struct Maybe_254) { .tag = Maybe_254_None_t } );
    }
}

static  struct Maybe_337   sequence_dash_maybe539 (    char  e1837 ,    struct Maybe_337  b1839 ) {
    struct Maybe_337  dref1840 = (  b1839 );
    if ( dref1840.tag == Maybe_337_None_t ) {
        return ( (struct Maybe_337) { .tag = Maybe_337_None_t } );
    }
    else {
        if ( dref1840.tag == Maybe_337_Just_t ) {
            struct Maybe_254  dref1842 = ( (  parse_dash_digit537 ) ( (  e1837 ) ) );
            if ( dref1842.tag == Maybe_254_None_t ) {
                return ( (struct Maybe_337) { .tag = Maybe_337_None_t } );
            }
            else {
                if ( dref1842.tag == Maybe_254_Just_t ) {
                    return ( ( Maybe_337_Just ) ( (  op_dash_add42 ( (  op_dash_mul44 ( ( dref1840 .stuff .Maybe_337_Just_s .field0 ) , (  from_dash_integral1 ( 10 ) ) ) ) , ( (  i32_dash_i64224 ) ( ( dref1842 .stuff .Maybe_254_Just_s .field0 ) ) ) ) ) ) );
                }
            }
        }
    }
}

static  struct Maybe_337   parse_dash_int538 (    const char*  s1834 ) {
    struct ConstStrIter_242  cs1844 = ( (  chars423 ) ( (  s1834 ) ) );
    struct Maybe_245  dref1845 = ( (  head398 ) ( (  cs1844 ) ) );
    if ( dref1845.tag == Maybe_245_Just_t ) {
        return ( (  reduce336 ) ( (  cs1844 ) ,  ( ( Maybe_337_Just ) ( (  from_dash_integral1 ( 0 ) ) ) ) ,  (  sequence_dash_maybe539 ) ) );
    }
    else {
        if ( dref1845.tag == Maybe_245_None_t ) {
            return ( (struct Maybe_337) { .tag = Maybe_337_None_t } );
        }
    }
}

static  struct Maybe_337   sequence_dash_maybe541 (    char  e1837 ,    struct Maybe_337  b1839 ) {
    struct Maybe_337  dref1840 = (  b1839 );
    if ( dref1840.tag == Maybe_337_None_t ) {
        return ( (struct Maybe_337) { .tag = Maybe_337_None_t } );
    }
    else {
        if ( dref1840.tag == Maybe_337_Just_t ) {
            struct Maybe_254  dref1842 = ( (  parse_dash_digit537 ) ( (  e1837 ) ) );
            if ( dref1842.tag == Maybe_254_None_t ) {
                return ( (struct Maybe_337) { .tag = Maybe_337_None_t } );
            }
            else {
                if ( dref1842.tag == Maybe_254_Just_t ) {
                    return ( ( Maybe_337_Just ) ( (  op_dash_add42 ( (  op_dash_mul44 ( ( dref1840 .stuff .Maybe_337_Just_s .field0 ) , (  from_dash_integral1 ( 10 ) ) ) ) , ( (  i32_dash_i64224 ) ( ( dref1842 .stuff .Maybe_254_Just_s .field0 ) ) ) ) ) ) );
                }
            }
        }
    }
}

static  struct Maybe_337   parse_dash_int540 (    struct TakeWhile_293  s1834 ) {
    struct TakeWhile_293  cs1844 = ( (  chars468 ) ( (  s1834 ) ) );
    struct Maybe_245  dref1845 = ( (  head400 ) ( (  cs1844 ) ) );
    if ( dref1845.tag == Maybe_245_Just_t ) {
        return ( (  reduce379 ) ( (  cs1844 ) ,  ( ( Maybe_337_Just ) ( (  from_dash_integral1 ( 0 ) ) ) ) ,  (  sequence_dash_maybe541 ) ) );
    }
    else {
        if ( dref1845.tag == Maybe_245_None_t ) {
            return ( (struct Maybe_337) { .tag = Maybe_337_None_t } );
        }
    }
}

static  struct Maybe_485   hex_dash_digit542 (    char  c1991 ) {
    if ( ( (  cmp473 ( (  c1991 ) , ( (  from_dash_charlike0 ) ( ( "0" ) ) ) ) != 0 ) && (  cmp473 ( (  c1991 ) , ( (  from_dash_charlike0 ) ( ( "9" ) ) ) ) != 2 ) ) ) {
        return ( ( Maybe_485_Just ) ( (  op_dash_sub56 ( ( (  char_dash_u8470 ) ( (  c1991 ) ) ) , ( (  char_dash_u8470 ) ( ( (  from_dash_charlike0 ) ( ( "0" ) ) ) ) ) ) ) ) );
    }
    if ( ( (  cmp473 ( (  c1991 ) , ( (  from_dash_charlike0 ) ( ( "a" ) ) ) ) != 0 ) && (  cmp473 ( (  c1991 ) , ( (  from_dash_charlike0 ) ( ( "f" ) ) ) ) != 2 ) ) ) {
        return ( ( Maybe_485_Just ) ( (  op_dash_add55 ( (  op_dash_sub56 ( ( (  char_dash_u8470 ) ( (  c1991 ) ) ) , ( (  char_dash_u8470 ) ( ( (  from_dash_charlike0 ) ( ( "a" ) ) ) ) ) ) ) , (  from_dash_integral5 ( 10 ) ) ) ) ) );
    }
    if ( ( (  cmp473 ( (  c1991 ) , ( (  from_dash_charlike0 ) ( ( "A" ) ) ) ) != 0 ) && (  cmp473 ( (  c1991 ) , ( (  from_dash_charlike0 ) ( ( "F" ) ) ) ) != 2 ) ) ) {
        return ( ( Maybe_485_Just ) ( (  op_dash_add55 ( (  op_dash_sub56 ( ( (  char_dash_u8470 ) ( (  c1991 ) ) ) , ( (  char_dash_u8470 ) ( ( (  from_dash_charlike0 ) ( ( "A" ) ) ) ) ) ) ) , (  from_dash_integral5 ( 10 ) ) ) ) ) );
    }
    return ( (struct Maybe_485) { .tag = Maybe_485_None_t } );
}

static  uint32_t   lam544 (    char  c1996 ) {
    return ( (  from_dash_integral3 ) ( ( (  u8_dash_i64233 ) ( ( (  or_dash_fail484 ) ( ( (  hex_dash_digit542 ) ( (  c1996 ) ) ) ,  ( ( StrConcat_441_StrConcat ) ( ( ( StrConcat_442_StrConcat ) ( ( (  from_dash_charlike0 ) ( ( "\"" ) ) ) ,  (  c1996 ) ) ) ,  ( "\" is not a hex digit." ) ) ) ) ) ) ) ) );
}

static  uint32_t   lam545 (    uint32_t  elem1998 ,    uint32_t  b2000 ) {
    return (  op_dash_add51 ( (  op_dash_mul53 ( (  b2000 ) , (  from_dash_integral3 ( 16 ) ) ) ) , (  elem1998 ) ) );
}

static  uint32_t   from_dash_hex543 (    const char*  arr1994 ) {
    return ( (  reduce381 ) ( ( (  map247 ) ( (  arr1994 ) ,  (  lam544 ) ) ) ,  (  from_dash_integral3 ( 0 ) ) ,  (  lam545 ) ) );
}

static  struct Maybe_221   get546 (    const char*  s2037 ) {
    return ( (  from_dash_nullable_dash_c_dash_str220 ) ( ( ( getenv ) ( (  s2037 ) ) ) ) );
}

static  enum Unit_141   show_dash_cursor547 (  ) {
    ( (  print_dash_str354 ) ( ( "\x1b[?25h" ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   hide_dash_cursor548 (  ) {
    ( (  print_dash_str354 ) ( ( "\x1b[?25l" ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   move_dash_cursor_dash_to549 (    uint32_t  x2014 ,    uint32_t  y2016 ) {
    uint32_t  x2017 = (  op_dash_add51 ( (  x2014 ) , (  from_dash_integral3 ( 1 ) ) ) );
    uint32_t  y2018 = (  op_dash_add51 ( (  y2016 ) , (  from_dash_integral3 ( 1 ) ) ) );
    ( (  print_dash_str448 ) ( ( ( StrConcat_449_StrConcat ) ( ( ( StrConcat_450_StrConcat ) ( ( ( StrConcat_451_StrConcat ) ( ( ( StrConcat_452_StrConcat ) ( ( "\x1b[" ) ,  (  y2018 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ";" ) ) ) ) ) ,  (  x2017 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "H" ) ) ) ) ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   reset_dash_cursor_dash_position550 (  ) {
    ( (  print_dash_str354 ) ( ( "\x1b[H" ) ) );
    return ( Unit_141_Unit );
}

static  struct Tuple2_413   get_dash_dimensions551 (  ) {
    struct Winsize_138  temp552 = ( ( (  zeroed187 ) ( ) ) );
    struct Winsize_138 *  ws2022 = ( &temp552 );
    if ( ( (  eq8 ( ( ( ioctl ) ( ( (  stdout_dash_fileno70 ) ( ) ) ,  ( (  tiocgwinsz86 ) ( ) ) ,  (  ws2022 ) ) ) , (  op_dash_neg50 ( (  from_dash_integral2 ( 1 ) ) ) ) ) ) || (  eq11 ( ( ( * (  ws2022 ) ) .f_ws_dash_col ) , (  from_dash_integral4 ( 0 ) ) ) ) ) ) {
        return ( ( Tuple2_413_Tuple2 ) ( (  from_dash_integral3 ( 80 ) ) ,  (  from_dash_integral3 ( 24 ) ) ) );
    }
    return ( ( Tuple2_413_Tuple2 ) ( ( (  u16_dash_u32230 ) ( ( ( * (  ws2022 ) ) .f_ws_dash_col ) ) ) ,  ( (  u16_dash_u32230 ) ( ( ( * (  ws2022 ) ) .f_ws_dash_row ) ) ) ) );
}

static  enum Unit_141   set_dash_default_dash_fg553 (  ) {
    ( (  print_dash_str354 ) ( ( "\x1b[39m" ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_default_dash_bg554 (  ) {
    ( (  print_dash_str354 ) ( ( "\x1b[49m" ) ) );
    return ( Unit_141_Unit );
}

static  enum ColorPalette_333   query_dash_palette555 (  ) {
    struct Maybe_221  colorterm2038 = ( (  get546 ) ( ( "COLORTERM" ) ) );
    struct Maybe_221  dref2039 = (  colorterm2038 );
    if ( dref2039.tag == Maybe_221_Just_t ) {
        if ( ( (  eq472 ( ( dref2039 .stuff .Maybe_221_Just_s .field0 ) , ( "truecolor" ) ) ) || (  eq472 ( ( dref2039 .stuff .Maybe_221_Just_s .field0 ) , ( "24bit" ) ) ) ) ) {
            return ( ColorPalette_333_PaletteRGB );
        }
    }
    else {
        if ( dref2039.tag == Maybe_221_None_t ) {
        }
    }
    struct Maybe_221  dref2041 = ( (  get546 ) ( ( "TERM" ) ) );
    if ( dref2041.tag == Maybe_221_Just_t ) {
        if ( (  eq472 ( ( dref2041 .stuff .Maybe_221_Just_s .field0 ) , ( "linux" ) ) ) ) {
            return ( ColorPalette_333_Palette8 );
        }
    }
    else {
        if ( dref2041.tag == Maybe_221_None_t ) {
        }
    }
    return ( ColorPalette_333_Palette16 );
}

static  enum Unit_141   set_dash_fg8556 (    enum Color8_17  color2057 ) {
    enum Color8_17  dref2058 = (  color2057 );
    switch (  dref2058 ) {
        case Color8_17_Black8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[30m" ) ) );
            break;
        }
        case Color8_17_Red8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[31m" ) ) );
            break;
        }
        case Color8_17_Green8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[32m" ) ) );
            break;
        }
        case Color8_17_Yellow8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[33m" ) ) );
            break;
        }
        case Color8_17_Blue8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[34m" ) ) );
            break;
        }
        case Color8_17_Magenta8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[35m" ) ) );
            break;
        }
        case Color8_17_Cyan8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[36m" ) ) );
            break;
        }
        case Color8_17_White8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[37m" ) ) );
            break;
        }
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_fg16557 (    enum Color16_18  color2061 ) {
    enum Color16_18  dref2062 = (  color2061 );
    switch (  dref2062 ) {
        case Color16_18_Black16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[30m" ) ) );
            break;
        }
        case Color16_18_Red16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[31m" ) ) );
            break;
        }
        case Color16_18_Green16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[32m" ) ) );
            break;
        }
        case Color16_18_Yellow16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[33m" ) ) );
            break;
        }
        case Color16_18_Blue16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[34m" ) ) );
            break;
        }
        case Color16_18_Magenta16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[35m" ) ) );
            break;
        }
        case Color16_18_Cyan16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[36m" ) ) );
            break;
        }
        case Color16_18_White16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[37m" ) ) );
            break;
        }
        case Color16_18_BrightBlack16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[90m" ) ) );
            break;
        }
        case Color16_18_BrightRed16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[91m" ) ) );
            break;
        }
        case Color16_18_BrightGreen16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[92m" ) ) );
            break;
        }
        case Color16_18_BrightYellow16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[93m" ) ) );
            break;
        }
        case Color16_18_BrightBlue16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[94m" ) ) );
            break;
        }
        case Color16_18_BrightMagenta16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[95m" ) ) );
            break;
        }
        case Color16_18_BrightCyan16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[96m" ) ) );
            break;
        }
        case Color16_18_BrightWhite16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[97m" ) ) );
            break;
        }
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_bg8558 (    enum Color8_17  color2065 ) {
    enum Color8_17  dref2066 = (  color2065 );
    switch (  dref2066 ) {
        case Color8_17_Black8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[40m" ) ) );
            break;
        }
        case Color8_17_Red8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[41m" ) ) );
            break;
        }
        case Color8_17_Green8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[42m" ) ) );
            break;
        }
        case Color8_17_Yellow8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[43m" ) ) );
            break;
        }
        case Color8_17_Blue8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[44m" ) ) );
            break;
        }
        case Color8_17_Magenta8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[45m" ) ) );
            break;
        }
        case Color8_17_Cyan8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[46m" ) ) );
            break;
        }
        case Color8_17_White8 : {
            ( (  print_dash_str354 ) ( ( "\x1b[47m" ) ) );
            break;
        }
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_bg16559 (    enum Color16_18  color2069 ) {
    enum Color16_18  dref2070 = (  color2069 );
    switch (  dref2070 ) {
        case Color16_18_Black16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[40m" ) ) );
            break;
        }
        case Color16_18_Red16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[41m" ) ) );
            break;
        }
        case Color16_18_Green16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[42m" ) ) );
            break;
        }
        case Color16_18_Yellow16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[43m" ) ) );
            break;
        }
        case Color16_18_Blue16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[44m" ) ) );
            break;
        }
        case Color16_18_Magenta16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[45m" ) ) );
            break;
        }
        case Color16_18_Cyan16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[46m" ) ) );
            break;
        }
        case Color16_18_White16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[47m" ) ) );
            break;
        }
        case Color16_18_BrightBlack16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[100m" ) ) );
            break;
        }
        case Color16_18_BrightRed16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[101m" ) ) );
            break;
        }
        case Color16_18_BrightGreen16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[102m" ) ) );
            break;
        }
        case Color16_18_BrightYellow16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[103m" ) ) );
            break;
        }
        case Color16_18_BrightBlue16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[104m" ) ) );
            break;
        }
        case Color16_18_BrightMagenta16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[105m" ) ) );
            break;
        }
        case Color16_18_BrightCyan16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[106m" ) ) );
            break;
        }
        case Color16_18_BrightWhite16 : {
            ( (  print_dash_str354 ) ( ( "\x1b[107m" ) ) );
            break;
        }
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   reset_dash_colors560 (  ) {
    ( (  print_dash_str354 ) ( ( "\x1b[0m" ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   clear_dash_screen561 (  ) {
    ( (  print_dash_str354 ) ( ( "\x1b[2J" ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_fg256562 (    uint8_t  color2075 ) {
    ( (  print_dash_str466 ) ( ( ( StrConcat_461_StrConcat ) ( ( ( StrConcat_462_StrConcat ) ( ( "\x1b[38;5;" ) ,  (  color2075 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_bg256563 (    uint8_t  color2078 ) {
    ( (  print_dash_str466 ) ( ( ( StrConcat_461_StrConcat ) ( ( ( StrConcat_462_StrConcat ) ( ( "\x1b[48;5;" ) ,  (  color2078 ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_fg_dash_rgb564 (    struct RGB_19  c2098 ) {
    ( (  print_dash_str456 ) ( ( ( StrConcat_457_StrConcat ) ( ( ( StrConcat_458_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( ( StrConcat_461_StrConcat ) ( ( ( StrConcat_462_StrConcat ) ( ( "\x1b[38;2;" ) ,  ( (  c2098 ) .f_r ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ";" ) ) ) ) ) ,  ( (  c2098 ) .f_g ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ";" ) ) ) ) ) ,  ( (  c2098 ) .f_b ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_bg_dash_rgb565 (    struct RGB_19  c2101 ) {
    ( (  print_dash_str456 ) ( ( ( StrConcat_457_StrConcat ) ( ( ( StrConcat_458_StrConcat ) ( ( ( StrConcat_459_StrConcat ) ( ( ( StrConcat_460_StrConcat ) ( ( ( StrConcat_461_StrConcat ) ( ( ( StrConcat_462_StrConcat ) ( ( "\x1b[48;2;" ) ,  ( (  c2101 ) .f_r ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ";" ) ) ) ) ) ,  ( (  c2101 ) .f_g ) ) ) ,  ( (  from_dash_charlike0 ) ( ( ";" ) ) ) ) ) ,  ( (  c2101 ) .f_b ) ) ) ,  ( (  from_dash_charlike0 ) ( ( "m" ) ) ) ) ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_fg566 (    struct Color_16  c2119 ) {
    struct Color_16  dref2120 = (  c2119 );
    if ( dref2120.tag == Color_16_ColorDefault_t ) {
        ( (  set_dash_default_dash_fg553 ) ( ) );
    }
    else {
        if ( dref2120.tag == Color_16_Color8_t ) {
            ( (  set_dash_fg8556 ) ( ( dref2120 .stuff .Color_16_Color8_s .field0 ) ) );
        }
        else {
            if ( dref2120.tag == Color_16_Color16_t ) {
                ( (  set_dash_fg16557 ) ( ( dref2120 .stuff .Color_16_Color16_s .field0 ) ) );
            }
            else {
                if ( dref2120.tag == Color_16_Color256_t ) {
                    ( (  set_dash_fg256562 ) ( ( dref2120 .stuff .Color_16_Color256_s .field0 ) ) );
                }
                else {
                    if ( dref2120.tag == Color_16_ColorRGB_t ) {
                        ( (  set_dash_fg_dash_rgb564 ) ( ( dref2120 .stuff .Color_16_ColorRGB_s .field0 ) ) );
                    }
                }
            }
        }
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_bg567 (    struct Color_16  c2127 ) {
    struct Color_16  dref2128 = (  c2127 );
    if ( dref2128.tag == Color_16_ColorDefault_t ) {
        ( (  set_dash_default_dash_bg554 ) ( ) );
    }
    else {
        if ( dref2128.tag == Color_16_Color8_t ) {
            ( (  set_dash_bg8558 ) ( ( dref2128 .stuff .Color_16_Color8_s .field0 ) ) );
        }
        else {
            if ( dref2128.tag == Color_16_Color16_t ) {
                ( (  set_dash_bg16559 ) ( ( dref2128 .stuff .Color_16_Color16_s .field0 ) ) );
            }
            else {
                if ( dref2128.tag == Color_16_Color256_t ) {
                    ( (  set_dash_bg256563 ) ( ( dref2128 .stuff .Color_16_Color256_s .field0 ) ) );
                }
                else {
                    if ( dref2128.tag == Color_16_ColorRGB_t ) {
                        ( (  set_dash_bg_dash_rgb565 ) ( ( dref2128 .stuff .Color_16_ColorRGB_s .field0 ) ) );
                    }
                }
            }
        }
    }
    return ( Unit_141_Unit );
}

static  uint32_t   next_dash_u32568 (  ) {
    return ( (  cast148 ) ( ( ( rand ) ( ) ) ) );
}

static  uint32_t   u32_dash_or569 (    uint32_t  l2555 ,    uint32_t  r2557 ) {
    return ( (  l2555 ) | (  r2557 ) );
}

static  uint32_t   u32_dash_ors570 (    struct SmolArray_61  vals2560 ) {
    return ( (  reduce339 ) ( (  vals2560 ) ,  (  from_dash_integral3 ( 0 ) ) ,  (  u32_dash_or569 ) ) );
}

static  uint32_t   u32_dash_ors571 (    struct SmolArray_64  vals2560 ) {
    return ( (  reduce363 ) ( (  vals2560 ) ,  (  from_dash_integral3 ( 0 ) ) ,  (  u32_dash_or569 ) ) );
}

static  uint32_t   u32_dash_ors572 (    struct SmolArray_67  vals2560 ) {
    return ( (  reduce370 ) ( (  vals2560 ) ,  (  from_dash_integral3 ( 0 ) ) ,  (  u32_dash_or569 ) ) );
}

static  uint32_t   u32_dash_and573 (    uint32_t  l2563 ,    uint32_t  r2565 ) {
    return ( (  l2563 ) & (  r2565 ) );
}

static  uint32_t   u32_dash_neg574 (    uint32_t  l2568 ) {
    return ( ~ (  l2568 ) );
}

static  struct Scanner_236   mk575 (    struct DynStr_529  s2607 ) {
    return ( (struct Scanner_236) { .f_s = ( (  chars528 ) ( (  s2607 ) ) ) } );
}

static  struct Maybe_337   scan_dash_int576 (    struct Scanner_236 *  sc2610 ) {
    struct TakeWhile_293  digit_dash_chars2611 = ( (  take_dash_while297 ) ( (  sc2610 ) ,  (  is_dash_digit536 ) ) );
    if ( ( (  null408 ) ( (  digit_dash_chars2611 ) ) ) ) {
        return ( (struct Maybe_337) { .tag = Maybe_337_None_t } );
    }
    ( (  drop_prime_409 ) ( (  sc2610 ) ,  ( (  count393 ) ( (  digit_dash_chars2611 ) ) ) ) );
    return ( (  parse_dash_int540 ) ( (  digit_dash_chars2611 ) ) );
}

static  struct timespec   now577 (  ) {
    struct timespec  temp578 = ( (  undefined99 ) ( ) );
    struct timespec *  t2624 = ( &temp578 );
    ( ( clock_gettime ) ( ( (  clock_dash_monotonic69 ) ( ) ) ,  (  t2624 ) ) );
    return ( * (  t2624 ) );
}

static  struct Termios_96   enable_dash_raw_dash_mode579 (  ) {
    struct Termios_96  temp580 = ( (  undefined95 ) ( ) );
    struct Termios_96 *  orig_dash_termios2662 = ( &temp580 );
    ( ( tcgetattr ) ( ( (  stdin_dash_fileno71 ) ( ) ) ,  ( (  cast_dash_ptr167 ) ( (  orig_dash_termios2662 ) ) ) ) );
    struct Termios_96  raw2663 = ( * (  orig_dash_termios2662 ) );
    raw2663 .f_c_dash_lflag = ( (  u32_dash_and573 ) ( ( (  raw2663 ) .f_c_dash_lflag ) ,  ( (  u32_dash_neg574 ) ( ( (  u32_dash_ors570 ) ( ( (  from_dash_listlike60 ) ( ( (struct Array_62) { ._arr = { ( (  echo72 ) ( ) ) , ( (  icanon73 ) ( ) ) , ( (  isig74 ) ( ) ) , ( ( (  iexten75 ) ( ) ) ) } } ) ) ) ) ) ) ) ) );
    raw2663 .f_c_dash_iflag = ( (  u32_dash_and573 ) ( ( (  raw2663 ) .f_c_dash_iflag ) ,  ( (  u32_dash_neg574 ) ( ( (  u32_dash_ors571 ) ( ( (  from_dash_listlike63 ) ( ( (struct Array_65) { ._arr = { ( (  brkint76 ) ( ) ) , ( (  icrnl77 ) ( ) ) , ( (  inpck78 ) ( ) ) , ( (  istrip79 ) ( ) ) , ( ( (  ixon80 ) ( ) ) ) } } ) ) ) ) ) ) ) ) );
    raw2663 .f_c_dash_oflag = ( (  u32_dash_and573 ) ( ( (  raw2663 ) .f_c_dash_oflag ) ,  ( (  u32_dash_neg574 ) ( ( (  u32_dash_ors572 ) ( ( (  from_dash_listlike66 ) ( ( (struct Array_68) { ._arr = { ( ( (  opost81 ) ( ) ) ) } } ) ) ) ) ) ) ) ) );
    raw2663 .f_c_dash_cflag = ( (  u32_dash_or569 ) ( ( (  raw2663 ) .f_c_dash_cflag ) ,  ( (  cs882 ) ( ) ) ) );
    ( (  set533 ) ( ( & ( (  raw2663 ) .f_c_dash_cc ) ) ,  ( (  vmin83 ) ( ) ) ,  (  from_dash_integral5 ( 0 ) ) ) );
    ( (  set533 ) ( ( & ( (  raw2663 ) .f_c_dash_cc ) ) ,  ( (  vtime84 ) ( ) ) ,  (  from_dash_integral5 ( 0 ) ) ) );
    ( ( tcsetattr ) ( ( (  stdin_dash_fileno71 ) ( ) ) ,  ( (  tcsa_dash_flush85 ) ( ) ) ,  ( (  cast_dash_ptr167 ) ( ( & (  raw2663 ) ) ) ) ) );
    return ( * (  orig_dash_termios2662 ) );
}

static  enum Unit_141   disable_dash_raw_dash_mode581 (    struct Termios_96 *  og_dash_termios2666 ) {
    ( ( tcsetattr ) ( ( (  stdin_dash_fileno71 ) ( ) ) ,  ( (  tcsa_dash_flush85 ) ( ) ) ,  ( (  cast_dash_ptr167 ) ( (  og_dash_termios2666 ) ) ) ) );
    return ( Unit_141_Unit );
}

static  struct Maybe_245   read_dash_byte582 (    int32_t  timeout_dash_ms2670 ) {
    struct Pollfd_176  pfd2671 = ( (struct Pollfd_176) { .f_fd = (  from_dash_integral2 ( 0 ) ) , .f_events = (  from_dash_integral4 ( 1 ) ) , .f_revents = (  from_dash_integral4 ( 0 ) ) } );
    if ( (  cmp39 ( ( ( poll ) ( ( (  cast_dash_ptr175 ) ( ( & (  pfd2671 ) ) ) ) ,  (  from_dash_integral2 ( 1 ) ) ,  (  timeout_dash_ms2670 ) ) ) , (  from_dash_integral2 ( 0 ) ) ) != 2 ) ) {
        return ( (struct Maybe_245) { .tag = Maybe_245_None_t } );
    }
    char  c2672 = ( ( (  zeroed195 ) ( ) ) );
    if ( (  cmp39 ( ( ( read ) ( ( (  stdin_dash_fileno71 ) ( ) ) ,  ( (  cast_dash_ptr177 ) ( ( & (  c2672 ) ) ) ) ,  (  from_dash_integral7 ( 1 ) ) ) ) , (  from_dash_integral2 ( 0 ) ) ) != 2 ) ) {
        return ( (struct Maybe_245) { .tag = Maybe_245_None_t } );
    }
    return ( ( Maybe_245_Just ) ( (  c2672 ) ) );
}

static  enum Unit_141   flush_dash_stdout583 (  ) {
    ( ( fflush ) ( ( (  null_dash_ptr215 ) ( ) ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   enable_dash_mouse584 (  ) {
    ( (  print_dash_str354 ) ( ( "\x1b[?1000h\x1b[?1006h" ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   disable_dash_mouse585 (  ) {
    ( (  print_dash_str354 ) ( ( "\x1b[?1000l\x1b[?1006l" ) ) );
    return ( Unit_141_Unit );
}

struct env587 {
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    ;
    bool *  should_dash_resize2676;
    ;
    ;
    ;
    ;
};

struct env588 {
    bool *  should_dash_resize2676;
};

struct funenv588 {
    enum Unit_141  (*fun) (  struct env588  ,    int32_t  );
    struct env588 env;
};

struct funenv588  _intr_sigarr[32];

static void _intr_sighandle (    int32_t  __intr__sig589 ) {
    struct funenv588  temp590 = _intr_sigarr [  __intr__sig589 ];
    temp590.fun ( temp590.env ,  __intr__sig589 );
}

static  enum Unit_141  _intr_register_signal (    int32_t  __intr__sig591 ,   struct funenv588  __intr__fun592 ) {
    _intr_sigarr [  __intr__sig591 ] =  __intr__fun592;
    signal(  __intr__sig591 , _intr_sighandle );
    return Unit_141_Unit;
}

static  enum Unit_141   lam588 (   struct env588 env ,    int32_t  dref2683 ) {
    (* env.should_dash_resize2676 ) = ( true );
    return ( Unit_141_Unit );
}

static  struct Tui_332   mk587 (   struct env587 env ) {
    struct Termios_96  og_dash_termios2678 = ( (  enable_dash_raw_dash_mode579 ) ( ) );
    ( (  hide_dash_cursor548 ) ( ) );
    ( (  reset_dash_colors560 ) ( ) );
    ( (  clear_dash_screen561 ) ( ) );
    ( (  enable_dash_mouse584 ) ( ) );
    ( (  flush_dash_stdout583 ) ( ) );
    enum ColorPalette_333  palette2679 = ( (  query_dash_palette555 ) ( ) );
    struct Tuple2_413  dims2680 = ( (  get_dash_dimensions551 ) ( ) );
    uint32_t  fps2681 = (  from_dash_integral3 ( 60 ) );
    struct timespec  last_dash_sync2682 = ( (  now577 ) ( ) );
    struct env588 envinst588 = {
        .should_dash_resize2676 = env.should_dash_resize2676 ,
    };
    ( _intr_register_signal ( (  from_dash_integral2 ( 28 ) ) , ( (struct funenv588){ .fun = lam588, .env = envinst588 } ) ) );
    return ( (struct Tui_332) { .f_width = ( (  fst412 ) ( (  dims2680 ) ) ) , .f_height = ( (  snd415 ) ( (  dims2680 ) ) ) , .f_target_dash_fps = (  fps2681 ) , .f_actual_dash_fps = (  from_dash_integral3 ( 0 ) ) , .f_last_dash_sync = (  last_dash_sync2682 ) , .f_fps_dash_ts = (  last_dash_sync2682 ) , .f_fps_dash_count = (  from_dash_integral3 ( 0 ) ) , .f_orig_dash_termios = (  og_dash_termios2678 ) , .f_palette = (  palette2679 ) } );
}

static  enum Unit_141   sync593 (    struct Tui_332 *  tui2686 ) {
    if ( (  eq9 ( ( ( * (  tui2686 ) ) .f_target_dash_fps ) , (  from_dash_integral3 ( 0 ) ) ) ) ) {
        return ( Unit_141_Unit );
    }
    int64_t  frame_dash_ns2687 = (  op_dash_div45 ( (  from_dash_integral1 ( 1000000000 ) ) , ( (  size_dash_i64222 ) ( ( (  u32_dash_size231 ) ( ( ( * (  tui2686 ) ) .f_target_dash_fps ) ) ) ) ) ) );
    struct timespec  temp594 = ( (  undefined99 ) ( ) );
    struct timespec *  now2688 = ( &temp594 );
    ( ( clock_gettime ) ( ( (  clock_dash_monotonic69 ) ( ) ) ,  (  now2688 ) ) );
    int64_t  elapsed_dash_ns2689 = (  op_dash_add42 ( (  op_dash_mul44 ( (  op_dash_sub43 ( ( ( * (  now2688 ) ) .tv_sec ) , ( ( ( * (  tui2686 ) ) .f_last_dash_sync ) .tv_sec ) ) ) , (  from_dash_integral1 ( 1000000000 ) ) ) ) , (  op_dash_sub43 ( ( ( * (  now2688 ) ) .tv_nsec ) , ( ( ( * (  tui2686 ) ) .f_last_dash_sync ) .tv_nsec ) ) ) ) );
    int64_t  sleep_dash_ns2690 = (  op_dash_sub43 ( (  frame_dash_ns2687 ) , (  elapsed_dash_ns2689 ) ) );
    if ( (  cmp36 ( (  sleep_dash_ns2690 ) , (  from_dash_integral1 ( 0 ) ) ) == 2 ) ) {
        struct timespec  temp595 = ( (struct timespec) { .tv_sec = (  from_dash_integral1 ( 0 ) ) , .tv_nsec = (  sleep_dash_ns2690 ) } );
        struct timespec *  ts2691 = ( &temp595 );
        ( ( nanosleep ) ( (  ts2691 ) ,  ( (  null_dash_ptr217 ) ( ) ) ) );
    }
    struct timespec  temp596 = ( (  undefined99 ) ( ) );
    struct timespec *  last_dash_sync2692 = ( &temp596 );
    ( ( clock_gettime ) ( ( (  clock_dash_monotonic69 ) ( ) ) ,  (  last_dash_sync2692 ) ) );
    (*  tui2686 ) .f_last_dash_sync = ( * (  last_dash_sync2692 ) );
    (*  tui2686 ) .f_fps_dash_count = (  op_dash_add51 ( ( ( * (  tui2686 ) ) .f_fps_dash_count ) , (  from_dash_integral3 ( 1 ) ) ) );
    int64_t  fps_dash_elapsed_dash_ms2693 = (  op_dash_add42 ( (  op_dash_mul44 ( (  op_dash_sub43 ( ( ( ( * (  tui2686 ) ) .f_last_dash_sync ) .tv_sec ) , ( ( ( * (  tui2686 ) ) .f_fps_dash_ts ) .tv_sec ) ) ) , (  from_dash_integral1 ( 1000 ) ) ) ) , (  op_dash_div45 ( (  op_dash_sub43 ( ( ( ( * (  tui2686 ) ) .f_last_dash_sync ) .tv_nsec ) , ( ( ( * (  tui2686 ) ) .f_fps_dash_ts ) .tv_nsec ) ) ) , (  from_dash_integral1 ( 1000000 ) ) ) ) ) );
    if ( (  cmp36 ( (  fps_dash_elapsed_dash_ms2693 ) , (  from_dash_integral1 ( 1000 ) ) ) != 0 ) ) {
        (*  tui2686 ) .f_actual_dash_fps = ( ( * (  tui2686 ) ) .f_fps_dash_count );
        (*  tui2686 ) .f_fps_dash_count = (  from_dash_integral3 ( 0 ) );
        (*  tui2686 ) .f_fps_dash_ts = ( ( * (  tui2686 ) ) .f_last_dash_sync );
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   deinit597 (    struct Tui_332 *  tui2696 ) {
    ( (  disable_dash_mouse585 ) ( ) );
    ( (  show_dash_cursor547 ) ( ) );
    ( (  reset_dash_colors560 ) ( ) );
    ( (  clear_dash_screen561 ) ( ) );
    ( (  reset_dash_cursor_dash_position550 ) ( ) );
    ( (  disable_dash_raw_dash_mode581 ) ( ( & ( ( * (  tui2696 ) ) .f_orig_dash_termios ) ) ) );
    ( (  flush_dash_stdout583 ) ( ) );
    return ( Unit_141_Unit );
}

static  bool   eq598 (    enum MouseButton_106  l2700 ,    enum MouseButton_106  r2702 ) {
    return (  eq9 ( ( (  cast_dash_on_dash_zeroed211 ) ( (  l2700 ) ) ) , ( ( (  cast_dash_on_dash_zeroed211 ) ( (  r2702 ) ) ) ) ) );
}

static  enum MouseButton_106   btn_dash_to_dash_mouse_dash_button599 (    int64_t  btn2708 ) {
    return ( {  int32_t  dref2709 = ( (  i64_dash_i32226 ) ( (  btn2708 ) ) ) ;  dref2709 == 0 ? ( MouseButton_106_MouseLeft ) :  dref2709 == 1 ? ( MouseButton_106_MouseMiddle ) :  dref2709 == 2 ? ( MouseButton_106_MouseRight ) :  dref2709 == 64 ? ( MouseButton_106_ScrollUp ) :  dref2709 == 65 ? ( MouseButton_106_ScrollDown ) : ( (  panic_prime_477 ) ( ( "incorrect mouse button" ) ) ) ; } );
}

struct Maybe_601 {
    enum {
        Maybe_601_None_t,
        Maybe_601_Just_t,
    } tag;
    union {
        struct {
            struct Key_302  field0;
        } Maybe_601_Just_s;
    } stuff;
};

static struct Maybe_601 Maybe_601_Just (  struct Key_302  field0 ) {
    return ( struct Maybe_601 ) { .tag = Maybe_601_Just_t, .stuff = { .Maybe_601_Just_s = { .field0 = field0 } } };
};

static  struct Maybe_601   parse_dash_ss3600 (    char  c2712 ) {
    if ( (  eq13 ( (  c2712 ) , ( (  from_dash_charlike0 ) ( ( "A" ) ) ) ) ) ) {
        return ( ( Maybe_601_Just ) ( ( (struct Key_302) { .tag = Key_302_Up_t } ) ) );
    }
    if ( (  eq13 ( (  c2712 ) , ( (  from_dash_charlike0 ) ( ( "B" ) ) ) ) ) ) {
        return ( ( Maybe_601_Just ) ( ( (struct Key_302) { .tag = Key_302_Down_t } ) ) );
    }
    if ( (  eq13 ( (  c2712 ) , ( (  from_dash_charlike0 ) ( ( "C" ) ) ) ) ) ) {
        return ( ( Maybe_601_Just ) ( ( (struct Key_302) { .tag = Key_302_Right_t } ) ) );
    }
    if ( (  eq13 ( (  c2712 ) , ( (  from_dash_charlike0 ) ( ( "D" ) ) ) ) ) ) {
        return ( ( Maybe_601_Just ) ( ( (struct Key_302) { .tag = Key_302_Left_t } ) ) );
    }
    if ( (  eq13 ( (  c2712 ) , ( (  from_dash_charlike0 ) ( ( "H" ) ) ) ) ) ) {
        return ( ( Maybe_601_Just ) ( ( (struct Key_302) { .tag = Key_302_Home_t } ) ) );
    }
    if ( (  eq13 ( (  c2712 ) , ( (  from_dash_charlike0 ) ( ( "F" ) ) ) ) ) ) {
        return ( ( Maybe_601_Just ) ( ( (struct Key_302) { .tag = Key_302_End_t } ) ) );
    }
    if ( (  eq13 ( (  c2712 ) , ( (  from_dash_charlike0 ) ( ( "P" ) ) ) ) ) ) {
        return ( ( Maybe_601_Just ) ( ( (struct Key_302) { .tag = Key_302_F1_t } ) ) );
    }
    if ( (  eq13 ( (  c2712 ) , ( (  from_dash_charlike0 ) ( ( "Q" ) ) ) ) ) ) {
        return ( ( Maybe_601_Just ) ( ( (struct Key_302) { .tag = Key_302_F2_t } ) ) );
    }
    if ( (  eq13 ( (  c2712 ) , ( (  from_dash_charlike0 ) ( ( "R" ) ) ) ) ) ) {
        return ( ( Maybe_601_Just ) ( ( (struct Key_302) { .tag = Key_302_F3_t } ) ) );
    }
    if ( (  eq13 ( (  c2712 ) , ( (  from_dash_charlike0 ) ( ( "S" ) ) ) ) ) ) {
        return ( ( Maybe_601_Just ) ( ( (struct Key_302) { .tag = Key_302_F4_t } ) ) );
    }
    return ( (struct Maybe_601) { .tag = Maybe_601_None_t } );
}

static  struct Maybe_300   parse_dash_csi602 (    struct DynStr_529  seq2715 ) {
    if ( (  eq12 ( ( ( (  seq2715 ) .f_contents ) .f_count ) , (  from_dash_integral7 ( 0 ) ) ) ) ) {
        return ( (struct Maybe_300) { .tag = Maybe_300_None_t } );
    }
    char  last2716 = (  elem_dash_get514 ( ( (  seq2715 ) .f_contents ) , (  op_dash_sub58 ( ( ( (  seq2715 ) .f_contents ) .f_count ) , (  from_dash_integral7 ( 1 ) ) ) ) ) );
    if ( ( (  eq13 ( (  elem_dash_get514 ( ( (  seq2715 ) .f_contents ) , (  from_dash_integral7 ( 0 ) ) ) ) , ( (  from_dash_charlike0 ) ( ( "<" ) ) ) ) ) && ( (  eq13 ( (  last2716 ) , ( (  from_dash_charlike0 ) ( ( "M" ) ) ) ) ) || (  eq13 ( (  last2716 ) , ( (  from_dash_charlike0 ) ( ( "m" ) ) ) ) ) ) ) ) {
        struct Scanner_236  temp603 = ( (  mk575 ) ( ( (  substr530 ) ( (  seq2715 ) ,  (  from_dash_integral7 ( 1 ) ) ,  ( ( (  seq2715 ) .f_contents ) .f_count ) ) ) ) );
        struct Scanner_236 *  sc2717 = ( &temp603 );
        struct Maybe_337  dref2718 = ( (  scan_dash_int576 ) ( (  sc2717 ) ) );
        if ( dref2718.tag == Maybe_337_None_t ) {
            return ( (struct Maybe_300) { .tag = Maybe_300_None_t } );
        }
        else {
            if ( dref2718.tag == Maybe_337_Just_t ) {
                ( (  next295 ) ( (  sc2717 ) ) );
                struct Maybe_337  dref2720 = ( (  scan_dash_int576 ) ( (  sc2717 ) ) );
                if ( dref2720.tag == Maybe_337_None_t ) {
                    return ( (struct Maybe_300) { .tag = Maybe_300_None_t } );
                }
                else {
                    if ( dref2720.tag == Maybe_337_Just_t ) {
                        ( (  next295 ) ( (  sc2717 ) ) );
                        struct Maybe_337  dref2722 = ( (  scan_dash_int576 ) ( (  sc2717 ) ) );
                        if ( dref2722.tag == Maybe_337_None_t ) {
                            return ( (struct Maybe_300) { .tag = Maybe_300_None_t } );
                        }
                        else {
                            if ( dref2722.tag == Maybe_337_Just_t ) {
                                return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Mouse ) ( ( (struct MouseEvent_303) { .f_button = ( (  btn_dash_to_dash_mouse_dash_button599 ) ( ( dref2718 .stuff .Maybe_337_Just_s .field0 ) ) ) , .f_x = (  op_dash_sub47 ( ( (  i64_dash_i32226 ) ( ( dref2720 .stuff .Maybe_337_Just_s .field0 ) ) ) , (  from_dash_integral2 ( 1 ) ) ) ) , .f_y = (  op_dash_sub47 ( ( (  i64_dash_i32226 ) ( ( dref2722 .stuff .Maybe_337_Just_s .field0 ) ) ) , (  from_dash_integral2 ( 1 ) ) ) ) , .f_pressed = (  eq13 ( (  last2716 ) , ( (  from_dash_charlike0 ) ( ( "M" ) ) ) ) ) } ) ) ) ) );
                            }
                        }
                    }
                }
            }
        }
    }
    if ( (  eq12 ( ( ( (  seq2715 ) .f_contents ) .f_count ) , (  from_dash_integral7 ( 1 ) ) ) ) ) {
        if ( (  eq13 ( (  last2716 ) , ( (  from_dash_charlike0 ) ( ( "A" ) ) ) ) ) ) {
            return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Up_t } ) ) ) ) );
        }
        if ( (  eq13 ( (  last2716 ) , ( (  from_dash_charlike0 ) ( ( "B" ) ) ) ) ) ) {
            return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Down_t } ) ) ) ) );
        }
        if ( (  eq13 ( (  last2716 ) , ( (  from_dash_charlike0 ) ( ( "C" ) ) ) ) ) ) {
            return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Right_t } ) ) ) ) );
        }
        if ( (  eq13 ( (  last2716 ) , ( (  from_dash_charlike0 ) ( ( "D" ) ) ) ) ) ) {
            return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Left_t } ) ) ) ) );
        }
        if ( (  eq13 ( (  last2716 ) , ( (  from_dash_charlike0 ) ( ( "H" ) ) ) ) ) ) {
            return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Home_t } ) ) ) ) );
        }
        if ( (  eq13 ( (  last2716 ) , ( (  from_dash_charlike0 ) ( ( "F" ) ) ) ) ) ) {
            return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_End_t } ) ) ) ) );
        }
        return ( (struct Maybe_300) { .tag = Maybe_300_None_t } );
    }
    if ( (  eq13 ( (  last2716 ) , ( (  from_dash_charlike0 ) ( ( "~" ) ) ) ) ) ) {
        struct Scanner_236  temp604 = ( (  mk575 ) ( (  seq2715 ) ) );
        struct Scanner_236 *  sc2724 = ( &temp604 );
        struct Maybe_337  dref2725 = ( (  scan_dash_int576 ) ( (  sc2724 ) ) );
        if ( dref2725.tag == Maybe_337_None_t ) {
            return ( (struct Maybe_300) { .tag = Maybe_300_None_t } );
        }
        else {
            if ( dref2725.tag == Maybe_337_Just_t ) {
                return ( {  int32_t  dref2727 = ( (  i64_dash_i32226 ) ( ( dref2725 .stuff .Maybe_337_Just_s .field0 ) ) ) ;  dref2727 == 1 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Home_t } ) ) ) ) ) :  dref2727 == 2 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Insert_t } ) ) ) ) ) :  dref2727 == 3 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Delete_t } ) ) ) ) ) :  dref2727 == 4 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_End_t } ) ) ) ) ) :  dref2727 == 5 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_PageUp_t } ) ) ) ) ) :  dref2727 == 6 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_PageDown_t } ) ) ) ) ) :  dref2727 == 15 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_F5_t } ) ) ) ) ) :  dref2727 == 17 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_F6_t } ) ) ) ) ) :  dref2727 == 18 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_F7_t } ) ) ) ) ) :  dref2727 == 19 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_F8_t } ) ) ) ) ) :  dref2727 == 20 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_F9_t } ) ) ) ) ) :  dref2727 == 21 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_F10_t } ) ) ) ) ) :  dref2727 == 23 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_F11_t } ) ) ) ) ) :  dref2727 == 24 ? ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_F12_t } ) ) ) ) ) : ( (struct Maybe_300) { .tag = Maybe_300_None_t } ) ; } );
            }
        }
    }
    return ( (struct Maybe_300) { .tag = Maybe_300_None_t } );
}

static  struct Maybe_300   read_dash_key605 (  ) {
    char  temp606 = ( (  undefined103 ) ( ) );
    char *  ch2729 = ( &temp606 );
    struct Maybe_245  dref2730 = ( (  read_dash_byte582 ) ( (  from_dash_integral2 ( 0 ) ) ) );
    if ( dref2730.tag == Maybe_245_None_t ) {
        return ( (struct Maybe_300) { .tag = Maybe_300_None_t } );
    }
    else {
        if ( dref2730.tag == Maybe_245_Just_t ) {
            (*  ch2729 ) = ( dref2730 .stuff .Maybe_245_Just_s .field0 );
        }
    }
    if ( (  eq10 ( ( (  char_dash_u8470 ) ( ( * (  ch2729 ) ) ) ) , (  from_dash_integral5 ( 13 ) ) ) ) ) {
        return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Enter_t } ) ) ) ) );
    }
    if ( (  eq10 ( ( (  char_dash_u8470 ) ( ( * (  ch2729 ) ) ) ) , (  from_dash_integral5 ( 127 ) ) ) ) ) {
        return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Backspace_t } ) ) ) ) );
    }
    if ( ( (  cmp41 ( ( (  char_dash_u8470 ) ( ( * (  ch2729 ) ) ) ) , (  from_dash_integral5 ( 27 ) ) ) == 0 ) && ( !  eq10 ( ( (  char_dash_u8470 ) ( ( * (  ch2729 ) ) ) ) , (  from_dash_integral5 ( 9 ) ) ) ) ) ) {
        char  letter2732 = ( (  i32_dash_char471 ) ( ( (  u32_dash_i32232 ) ( ( (  u32_dash_or569 ) ( ( (  i32_dash_u32223 ) ( ( (  char_dash_i32469 ) ( ( * (  ch2729 ) ) ) ) ) ) ,  ( (  from_dash_hex543 ) ( ( "60" ) ) ) ) ) ) ) ) );
        return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( ( Key_302_Ctrl ) ( (  letter2732 ) ) ) ) ) ) );
    }
    if ( ( !  eq10 ( ( (  char_dash_u8470 ) ( ( * (  ch2729 ) ) ) ) , (  from_dash_integral5 ( 27 ) ) ) ) ) {
        if ( (  cmp41 ( ( (  char_dash_u8470 ) ( ( * (  ch2729 ) ) ) ) , (  from_dash_integral5 ( 127 ) ) ) == 2 ) ) {
            return ( (  read_dash_key605 ) ( ) );
        } else {
            return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( ( Key_302_Char ) ( ( * (  ch2729 ) ) ) ) ) ) ) );
        }
    }
    char  temp607 = ( (  undefined103 ) ( ) );
    char *  ch22733 = ( &temp607 );
    struct Maybe_245  dref2734 = ( (  read_dash_byte582 ) ( (  from_dash_integral2 ( 50 ) ) ) );
    if ( dref2734.tag == Maybe_245_None_t ) {
        return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Escape_t } ) ) ) ) );
    }
    else {
        if ( dref2734.tag == Maybe_245_Just_t ) {
            (*  ch22733 ) = ( dref2734 .stuff .Maybe_245_Just_s .field0 );
        }
    }
    if ( (  eq13 ( ( * (  ch22733 ) ) , ( (  from_dash_charlike0 ) ( ( "[" ) ) ) ) ) ) {
        struct Array_145  temp608 = ( ( (  zeroed197 ) ( ) ) );
        struct Array_145 *  seq2736 = ( &temp608 );
        int32_t  slen2737 = (  from_dash_integral2 ( 0 ) );
        while ( (  cmp39 ( (  slen2737 ) , (  from_dash_integral2 ( 31 ) ) ) == 0 ) ) {
            char  temp609 = ( (  undefined103 ) ( ) );
            char *  sc2738 = ( &temp609 );
            struct Maybe_245  dref2739 = ( (  read_dash_byte582 ) ( (  from_dash_integral2 ( 50 ) ) ) );
            if ( dref2739.tag == Maybe_245_None_t ) {
                break;
            }
            else {
                if ( dref2739.tag == Maybe_245_Just_t ) {
                    (*  sc2738 ) = ( dref2739 .stuff .Maybe_245_Just_s .field0 );
                }
            }
            ( (  set534 ) ( (  seq2736 ) ,  ( (  i32_dash_size225 ) ( (  slen2737 ) ) ) ,  ( * (  sc2738 ) ) ) );
            slen2737 = (  op_dash_add46 ( (  slen2737 ) , (  from_dash_integral2 ( 1 ) ) ) );
            if ( ( (  cmp41 ( ( (  char_dash_u8470 ) ( ( * (  sc2738 ) ) ) ) , (  from_dash_integral5 ( 64 ) ) ) != 0 ) && (  cmp41 ( ( (  char_dash_u8470 ) ( ( * (  sc2738 ) ) ) ) , (  from_dash_integral5 ( 126 ) ) ) != 2 ) ) ) {
                break;
            }
        }
        return ( (  parse_dash_csi602 ) ( ( (struct DynStr_529) { .f_contents = ( (  subslice504 ) ( ( (  as_dash_slice535 ) ( (  seq2736 ) ) ) ,  (  from_dash_integral7 ( 0 ) ) ,  ( (  i32_dash_size225 ) ( (  slen2737 ) ) ) ) ) } ) ) );
    }
    if ( (  eq13 ( ( * (  ch22733 ) ) , ( (  from_dash_charlike0 ) ( ( "O" ) ) ) ) ) ) {
        char  temp610 = ( (  undefined103 ) ( ) );
        char *  sc2741 = ( &temp610 );
        struct Maybe_245  dref2742 = ( (  read_dash_byte582 ) ( (  from_dash_integral2 ( 50 ) ) ) );
        if ( dref2742.tag == Maybe_245_None_t ) {
            return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Escape_t } ) ) ) ) );
        }
        else {
            if ( dref2742.tag == Maybe_245_Just_t ) {
                (*  sc2741 ) = ( dref2742 .stuff .Maybe_245_Just_s .field0 );
            }
        }
        struct Maybe_601  dref2744 = ( (  parse_dash_ss3600 ) ( ( * (  sc2741 ) ) ) );
        if ( dref2744.tag == Maybe_601_None_t ) {
            return ( (struct Maybe_300) { .tag = Maybe_300_None_t } );
        }
        else {
            if ( dref2744.tag == Maybe_601_Just_t ) {
                return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( dref2744 .stuff .Maybe_601_Just_s .field0 ) ) ) ) );
            }
        }
    }
    return ( ( Maybe_300_Just ) ( ( ( InputEvent_301_Key ) ( ( (struct Key_302) { .tag = Key_302_Escape_t } ) ) ) ) );
}

struct env611 {
    ;
    ;
    bool *  should_dash_resize2676;
    ;
};

static  bool   update_dash_dimensions611 (   struct env611 env ,    struct Tui_332 *  tui2748 ) {
    if ( ( ! ( * ( env.should_dash_resize2676 ) ) ) ) {
        return ( false );
    }
    (* env.should_dash_resize2676 ) = ( false );
    struct Tuple2_413  dim2749 = ( (  get_dash_dimensions551 ) ( ) );
    uint32_t  w2750 = ( (  fst412 ) ( (  dim2749 ) ) );
    uint32_t  h2751 = ( (  snd415 ) ( (  dim2749 ) ) );
    (*  tui2748 ) .f_width = (  w2750 );
    (*  tui2748 ) .f_height = (  h2751 );
    return ( true );
}

static  struct Cell_15   lam613 (    struct Cell_15  dref2769 ) {
    return ( (struct Cell_15) { .f_c = ( (  from_dash_charlike0 ) ( ( " " ) ) ) , .f_fg = ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) , .f_bg = ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) } );
}

static  struct Cell_15   lam614 (    struct Cell_15  dref2771 ) {
    return ( (struct Cell_15) { .f_c = ( (  from_dash_charlike0 ) ( ( " " ) ) ) , .f_fg = ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) , .f_bg = ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) } );
}

static  struct Screen_330   mk_dash_screen612 (    struct Tui_332 *  tui2765 ,    enum CAllocator_331  al2767 ) {
    struct Slice_313  cur2768 = ( (  allocate525 ) ( (  al2767 ) ,  ( (  u32_dash_size231 ) ( (  op_dash_mul53 ( ( ( * (  tui2765 ) ) .f_width ) , ( ( * (  tui2765 ) ) .f_height ) ) ) ) ) ) );
    ( (  map519 ) ( (  cur2768 ) ,  (  lam613 ) ) );
    struct Slice_313  prev2770 = ( (  allocate525 ) ( (  al2767 ) ,  ( (  u32_dash_size231 ) ( (  op_dash_mul53 ( ( ( * (  tui2765 ) ) .f_width ) , ( ( * (  tui2765 ) ) .f_height ) ) ) ) ) ) );
    ( (  map520 ) ( (  prev2770 ) ,  (  lam614 ) ) );
    return ( (struct Screen_330) { .f_current = (  cur2768 ) , .f_previous = (  prev2770 ) , .f_al = (  al2767 ) , .f_tui = (  tui2765 ) , .f_requires_dash_full_dash_redraw = ( false ) , .f_default_dash_fg = ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) , .f_default_dash_bg = ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) } );
}

static  enum Unit_141   free_dash_screen615 (    struct Screen_330 *  screen2774 ) {
    enum CAllocator_331  al2775 = ( ( * (  screen2774 ) ) .f_al );
    ( (  free526 ) ( (  al2775 ) ,  ( ( * (  screen2774 ) ) .f_current ) ) );
    ( (  free526 ) ( (  al2775 ) ,  ( ( * (  screen2774 ) ) .f_previous ) ) );
    return ( Unit_141_Unit );
}

static  struct Cell_15   lam617 (    struct Cell_15  dref2779 ) {
    return ( (struct Cell_15) { .f_c = ( (  from_dash_charlike0 ) ( ( " " ) ) ) , .f_fg = ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) , .f_bg = ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) } );
}

static  enum Unit_141   clear_dash_screen616 (    struct Screen_330 *  screen2778 ) {
    ( (  map521 ) ( ( ( * (  screen2778 ) ) .f_current ) ,  (  lam617 ) ) );
    return ( Unit_141_Unit );
}

struct RenderState_619 {
    uint32_t  f_x;
    uint32_t  f_y;
    struct Color_16  f_fg;
    struct Color_16  f_bg;
    uint32_t  f_changes;
};

static  enum Unit_141   emit_dash_cell618 (    struct RenderState_619 *  rs2783 ,    struct Cell_15 *  c2785 ,    uint32_t  x2787 ,    uint32_t  y2789 ) {
    if ( ( ( !  eq9 ( (  x2787 ) , ( ( * (  rs2783 ) ) .f_x ) ) ) || ( !  eq9 ( (  y2789 ) , ( ( * (  rs2783 ) ) .f_y ) ) ) ) ) {
        ( (  move_dash_cursor_dash_to549 ) ( (  x2787 ) ,  (  y2789 ) ) );
        (*  rs2783 ) .f_x = (  x2787 );
        (*  rs2783 ) .f_y = (  y2789 );
    }
    char  char2790 = ( ( * (  c2785 ) ) .f_c );
    struct Color_16  bg2791 = ( ( * (  c2785 ) ) .f_bg );
    if ( ( ( (  eq13 ( (  char2790 ) , ( (  from_dash_charlike0 ) ( ( "\t" ) ) ) ) ) || (  eq13 ( (  char2790 ) , ( (  from_dash_charlike0 ) ( ( "\r" ) ) ) ) ) ) || (  eq13 ( (  char2790 ) , ( (  from_dash_charlike0 ) ( ( "\n" ) ) ) ) ) ) ) {
        char2790 = ( (  from_dash_charlike0 ) ( ( " " ) ) );
        bg2791 = ( ( Color_16_Color8 ) ( ( Color8_17_Red8 ) ) );
    }
    if ( ( !  eq21 ( ( ( * (  rs2783 ) ) .f_fg ) , ( ( * (  c2785 ) ) .f_fg ) ) ) ) {
        ( (  set_dash_fg566 ) ( ( ( * (  c2785 ) ) .f_fg ) ) );
        (*  rs2783 ) .f_fg = ( ( * (  c2785 ) ) .f_fg );
    }
    if ( ( !  eq21 ( ( ( * (  rs2783 ) ) .f_bg ) , (  bg2791 ) ) ) ) {
        ( (  set_dash_bg567 ) ( (  bg2791 ) ) );
        (*  rs2783 ) .f_bg = (  bg2791 );
    }
    ( (  print_dash_str361 ) ( (  char2790 ) ) );
    (*  rs2783 ) .f_x = (  op_dash_add51 ( ( ( * (  rs2783 ) ) .f_x ) , (  from_dash_integral3 ( 1 ) ) ) );
    return ( Unit_141_Unit );
}

static  uint32_t   render_dash_screen620 (    struct Screen_330 *  screen2794 ) {
    int32_t  w2795 = ( (  u32_dash_i32232 ) ( ( ( * ( ( * (  screen2794 ) ) .f_tui ) ) .f_width ) ) );
    int32_t  h2796 = ( (  u32_dash_i32232 ) ( ( ( * ( ( * (  screen2794 ) ) .f_tui ) ) .f_height ) ) );
    struct RenderState_619  temp621 = ( (struct RenderState_619) { .f_x = (  from_dash_integral3 ( 0 ) ) , .f_y = (  from_dash_integral3 ( 0 ) ) , .f_fg = ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) , .f_bg = ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) , .f_changes = (  from_dash_integral3 ( 0 ) ) } );
    struct RenderState_619 *  rs2797 = ( &temp621 );
    ( (  move_dash_cursor_dash_to549 ) ( (  from_dash_integral3 ( 0 ) ) ,  (  from_dash_integral3 ( 0 ) ) ) );
    struct RangeIter_252  temp622 =  into_dash_iter251 ( ( (  to249 ) ( (  from_dash_integral2 ( 0 ) ) ,  (  op_dash_sub47 ( (  h2796 ) , (  from_dash_integral2 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_254  __cond623 =  next253 (&temp622);
        if (  __cond623 .tag == 0 ) {
            break;
        }
        int32_t  y2799 =  __cond623 .stuff .Maybe_254_Just_s .field0;
        struct RangeIter_252  temp624 =  into_dash_iter251 ( ( (  to249 ) ( (  from_dash_integral2 ( 0 ) ) ,  (  op_dash_sub47 ( (  w2795 ) , (  from_dash_integral2 ( 1 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_254  __cond625 =  next253 (&temp624);
            if (  __cond625 .tag == 0 ) {
                break;
            }
            int32_t  x2801 =  __cond625 .stuff .Maybe_254_Just_s .field0;
            size_t  i2802 = ( (  i32_dash_size225 ) ( (  op_dash_add46 ( (  op_dash_mul48 ( (  y2799 ) , (  w2795 ) ) ) , (  x2801 ) ) ) ) );
            struct Cell_15 *  cur2803 = ( (  get_dash_ptr491 ) ( ( ( * (  screen2794 ) ) .f_current ) ,  (  i2802 ) ) );
            struct Cell_15 *  prev2804 = ( (  get_dash_ptr491 ) ( ( ( * (  screen2794 ) ) .f_previous ) ,  (  i2802 ) ) );
            if ( ( ( !  eq14 ( (  cur2803 ) , (  prev2804 ) ) ) || ( ( * (  screen2794 ) ) .f_requires_dash_full_dash_redraw ) ) ) {
                (*  rs2797 ) .f_changes = (  op_dash_add51 ( ( ( * (  rs2797 ) ) .f_changes ) , (  from_dash_integral3 ( 1 ) ) ) );
                ( (  emit_dash_cell618 ) ( (  rs2797 ) ,  (  cur2803 ) ,  ( (  i32_dash_u32223 ) ( (  x2801 ) ) ) ,  ( (  i32_dash_u32223 ) ( (  y2799 ) ) ) ) );
                (*  prev2804 ) = ( * (  cur2803 ) );
            }
        }
    }
    (*  screen2794 ) .f_requires_dash_full_dash_redraw = ( false );
    ( (  reset_dash_colors560 ) ( ) );
    ( (  flush_dash_stdout583 ) ( ) );
    return ( ( * (  rs2797 ) ) .f_changes );
}

struct funenv611 {
    bool  (*fun) (  struct env611  ,    struct Tui_332 *  );
    struct env611 env;
};

struct env626 {
    ;
    ;
    ;
    ;
    ;
    struct env611 envinst611;
};

static  bool   resize_dash_screen_dash_if_dash_needed626 (   struct env626 env ,    struct Screen_330 *  screen2807 ) {
    struct Tui_332 *  tui2808 = ( ( * (  screen2807 ) ) .f_tui );
    struct funenv611  temp627 = ( (struct funenv611){ .fun = update_dash_dimensions611, .env =  env.envinst611  } );
    if ( ( ! ( temp627.fun ( temp627.env ,  (  tui2808 ) ) ) ) ) {
        return ( false );
    }
    (*  screen2807 ) .f_requires_dash_full_dash_redraw = ( true );
    uint32_t  w2809 = ( ( * ( ( * (  screen2807 ) ) .f_tui ) ) .f_width );
    uint32_t  h2810 = ( ( * ( ( * (  screen2807 ) ) .f_tui ) ) .f_height );
    size_t  nusz2811 = ( (  u32_dash_size231 ) ( (  op_dash_mul53 ( (  w2809 ) , (  h2810 ) ) ) ) );
    if ( (  cmp38 ( (  nusz2811 ) , ( ( ( * (  screen2807 ) ) .f_current ) .f_count ) ) != 2 ) ) {
        return ( true );
    }
    struct Screen_330  nuscreen2812 = ( (  mk_dash_screen612 ) ( (  tui2808 ) ,  ( ( * (  screen2807 ) ) .f_al ) ) );
    (*  screen2807 ) .f_current = ( (  nuscreen2812 ) .f_current );
    (*  screen2807 ) .f_previous = ( (  nuscreen2812 ) .f_previous );
    return ( true );
}

static  enum Unit_141   set_dash_screen_dash_fg628 (    struct Screen_330 *  screen2815 ,    struct Color_16  c2817 ) {
    (*  screen2815 ) .f_default_dash_fg = (  c2817 );
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_screen_dash_bg629 (    struct Screen_330 *  screen2820 ,    struct Color_16  c2822 ) {
    (*  screen2820 ) .f_default_dash_bg = (  c2822 );
    return ( Unit_141_Unit );
}

static  enum Unit_141   set_dash_screen_dash_colors630 (    struct Screen_330 *  screen2825 ,    struct Color_16  fg2827 ,    struct Color_16  bg2829 ) {
    (*  screen2825 ) .f_default_dash_fg = (  fg2827 );
    (*  screen2825 ) .f_default_dash_bg = (  bg2829 );
    return ( Unit_141_Unit );
}

static  struct Maybe_487   get_dash_cell_dash_ptr631 (    struct Screen_330 *  screen2836 ,    int32_t  x2838 ,    int32_t  y2840 ) {
    int32_t  w2841 = ( (  u32_dash_i32232 ) ( ( ( * ( ( * (  screen2836 ) ) .f_tui ) ) .f_width ) ) );
    if ( ( (  cmp39 ( (  x2838 ) , (  from_dash_integral2 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  x2838 ) , (  w2841 ) ) != 0 ) ) ) {
        return ( (struct Maybe_487) { .tag = Maybe_487_None_t } );
    }
    if ( ( (  cmp39 ( (  y2840 ) , (  from_dash_integral2 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  y2840 ) , ( (  u32_dash_i32232 ) ( ( ( * ( ( * (  screen2836 ) ) .f_tui ) ) .f_height ) ) ) ) != 0 ) ) ) {
        return ( (struct Maybe_487) { .tag = Maybe_487_None_t } );
    }
    size_t  i2842 = ( (  i32_dash_size225 ) ( (  op_dash_add46 ( (  op_dash_mul48 ( (  y2840 ) , (  w2841 ) ) ) , (  x2838 ) ) ) ) );
    return ( ( Maybe_487_Just ) ( ( (  get_dash_ptr491 ) ( ( ( * (  screen2836 ) ) .f_current ) ,  (  i2842 ) ) ) ) );
}

static  enum Unit_141   fill_dash_default632 (    struct Screen_330 *  screen2845 ) {
    struct RangeIter_252  temp633 =  into_dash_iter251 ( ( (  to249 ) ( (  from_dash_integral2 ( 0 ) ) ,  (  op_dash_sub47 ( ( (  u32_dash_i32232 ) ( ( ( * ( ( * (  screen2845 ) ) .f_tui ) ) .f_height ) ) ) , (  from_dash_integral2 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_254  __cond634 =  next253 (&temp633);
        if (  __cond634 .tag == 0 ) {
            break;
        }
        int32_t  y2847 =  __cond634 .stuff .Maybe_254_Just_s .field0;
        struct RangeIter_252  temp635 =  into_dash_iter251 ( ( (  to249 ) ( (  from_dash_integral2 ( 0 ) ) ,  (  op_dash_sub47 ( ( (  u32_dash_i32232 ) ( ( ( * ( ( * (  screen2845 ) ) .f_tui ) ) .f_width ) ) ) , (  from_dash_integral2 ( 1 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_254  __cond636 =  next253 (&temp635);
            if (  __cond636 .tag == 0 ) {
                break;
            }
            int32_t  x2849 =  __cond636 .stuff .Maybe_254_Just_s .field0;
            struct Cell_15 *  cell2850 = ( (  or_dash_fail486 ) ( ( (  get_dash_cell_dash_ptr631 ) ( (  screen2845 ) ,  (  x2849 ) ,  (  y2847 ) ) ) ,  ( "no cell??" ) ) );
            (*  cell2850 ) .f_bg = ( ( * (  screen2845 ) ) .f_default_dash_bg );
        }
    }
    return ( Unit_141_Unit );
}

static  enum Unit_141   put_dash_char637 (    struct Screen_330 *  screen2853 ,    char  c2855 ,    int32_t  x2857 ,    int32_t  y2859 ) {
    int32_t  w2860 = ( (  u32_dash_i32232 ) ( ( ( * ( ( * (  screen2853 ) ) .f_tui ) ) .f_width ) ) );
    if ( ( ( ( (  cmp39 ( (  x2857 ) , (  w2860 ) ) != 0 ) || (  cmp39 ( (  y2859 ) , ( (  u32_dash_i32232 ) ( ( ( * ( ( * (  screen2853 ) ) .f_tui ) ) .f_height ) ) ) ) != 0 ) ) || (  cmp39 ( (  x2857 ) , (  from_dash_integral2 ( 0 ) ) ) == 0 ) ) || (  cmp39 ( (  y2859 ) , (  from_dash_integral2 ( 0 ) ) ) == 0 ) ) ) {
        return ( Unit_141_Unit );
    }
    size_t  i2861 = ( (  i32_dash_size225 ) ( (  op_dash_add46 ( (  op_dash_mul48 ( (  y2859 ) , (  w2860 ) ) ) , (  x2857 ) ) ) ) );
    struct Color_16  fg2862 = ( ( * (  screen2853 ) ) .f_default_dash_fg );
    struct Color_16  bg2863 = ( ( * (  screen2853 ) ) .f_default_dash_bg );
    char  c2864 = (  c2855 );
    ( (  set501 ) ( ( ( * (  screen2853 ) ) .f_current ) ,  (  i2861 ) ,  ( (struct Cell_15) { .f_c = (  c2864 ) , .f_fg = (  fg2862 ) , .f_bg = (  bg2863 ) } ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   lam329 (   struct env329 env ,    struct Tuple2_280  dref2878 ) {
    ( (  put_dash_char637 ) ( ( env.screen2867 ) ,  ( dref2878 .field0 ) ,  (  op_dash_add46 ( ( env.x2876 ) , ( dref2878 .field1 ) ) ) ,  ( env.y2873 ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   draw_dash_str638 (    struct Screen_330 *  screen2867 ,    const char*  s2869 ,    int32_t  x2871 ,    int32_t  y2873 ) {
    int32_t  w2874 = ( (  u32_dash_i32232 ) ( ( ( * ( ( * (  screen2867 ) ) .f_tui ) ) .f_width ) ) );
    if ( ( (  cmp39 ( (  y2873 ) , (  from_dash_integral2 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  y2873 ) , ( (  u32_dash_i32232 ) ( ( ( * ( ( * (  screen2867 ) ) .f_tui ) ) .f_height ) ) ) ) != 0 ) ) ) {
        return ( Unit_141_Unit );
    }
    int32_t  i2875 = (  op_dash_add46 ( (  op_dash_mul48 ( (  y2873 ) , (  w2874 ) ) ) , (  x2871 ) ) );
    int32_t  x2876 = ( (  min422 ) ( (  x2871 ) ,  (  w2874 ) ) );
    size_t  max_dash_len2877 = ( (  i32_dash_size225 ) ( (  op_dash_sub47 ( (  w2874 ) , (  x2876 ) ) ) ) );
    struct env329 envinst329 = {
        .y2873 =  y2873 ,
        .screen2867 =  screen2867 ,
        .x2876 =  x2876 ,
    };
    ( (  for_dash_each328 ) ( ( (  zip285 ) ( ( (  chars423 ) ( (  s2869 ) ) ) ,  ( (  from255 ) ( (  from_dash_integral2 ( 0 ) ) ) ) ) ) ,  ( (struct funenv329){ .fun = lam329, .env = envinst329 } ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   draw_dash_str_dash_center639 (    struct Screen_330 *  screen2895 ,    const char*  s2897 ,    int32_t  x2899 ,    int32_t  y2901 ) {
    int32_t  slen2902 = ( (  size_dash_i32228 ) ( ( (  count395 ) ( ( (  chars423 ) ( (  s2897 ) ) ) ) ) ) );
    int32_t  x2903 = (  op_dash_sub47 ( (  x2899 ) , (  op_dash_div49 ( (  slen2902 ) , (  from_dash_integral2 ( 2 ) ) ) ) ) );
    ( (  draw_dash_str638 ) ( (  screen2895 ) ,  (  s2897 ) ,  (  x2903 ) ,  (  y2901 ) ) );
    return ( Unit_141_Unit );
}

static  struct Slice_503   get640 (  ) {
    return ( (struct Slice_503) { .f_ptr = ( (  offset_dash_ptr112 ) ( ( _global_argv ) ,  (  from_dash_integral1 ( 1 ) ) ) ) , .f_count = (  op_dash_sub58 ( ( _global_argc ) , (  from_dash_integral7 ( 1 ) ) ) ) } );
}

enum GameState_642 {
    GameState_642_InProgress,
    GameState_642_Failed,
    GameState_642_Won,
};

struct Tuple2_643 {
    enum GameState_642  field0;
    enum GameState_642  field1;
};

static struct Tuple2_643 Tuple2_643_Tuple2 (  enum GameState_642  field0 ,  enum GameState_642  field1 ) {
    return ( struct Tuple2_643 ) { .field0 = field0 ,  .field1 = field1 };
};

static  bool   eq641 (    enum GameState_642  l2486 ,    enum GameState_642  r2488 ) {
    return ( {  struct Tuple2_643  dref2489 = ( ( Tuple2_643_Tuple2 ) ( (  l2486 ) ,  (  r2488 ) ) ) ;  dref2489 .field0 == GameState_642_InProgress &&  dref2489 .field1 == GameState_642_InProgress ? ( true ) :  dref2489 .field0 == GameState_642_Failed &&  dref2489 .field1 == GameState_642_Failed ? ( true ) :  dref2489 .field0 == GameState_642_Won &&  dref2489 .field1 == GameState_642_Won ? ( true ) : ( false ) ; } );
}

struct TileMap_645 {
    struct Slice_262  f_tiles;
    int32_t  f_width;
    int32_t  f_height;
};

static  struct TileMap_645   mk_dash_tiles644 (    size_t  w2494 ,    size_t  h2496 ,    enum CAllocator_331  al2498 ) {
    struct Slice_262  rows2499 = ( (  allocate523 ) ( (  al2498 ) ,  (  h2496 ) ) );
    struct SliceAddressIter_507  temp646 =  into_dash_iter508 ( ( (  addresses506 ) ( (  rows2499 ) ) ) );
    while (true) {
        struct Maybe_510  __cond647 =  next509 (&temp646);
        if (  __cond647 .tag == 0 ) {
            break;
        }
        struct Slice_90 *  row2501 =  __cond647 .stuff .Maybe_510_Just_s .field0;
        (*  row2501 ) = ( (  default527 ) ( (  al2498 ) ,  (  w2494 ) ,  ( (struct Tile_91) { .f_hidden = ( true ) , .f_is_dash_bomb = ( false ) , .f_flagged = ( false ) } ) ) );
    }
    return ( (struct TileMap_645) { .f_tiles = (  rows2499 ) , .f_width = ( (  size_dash_i32228 ) ( (  w2494 ) ) ) , .f_height = ( (  size_dash_i32228 ) ( (  h2496 ) ) ) } );
}

static  enum Unit_141   map_dash_tile648 (    struct TileMap_645  tilemap2504 ,    int32_t  x2506 ,    int32_t  y2508 ,    struct Tile_91 (*  fun2510 )(    struct Tile_91  ) ) {
    struct Tile_91 *  tp2511 = ( (  get_dash_ptr490 ) ( (  elem_dash_get511 ( ( (  tilemap2504 ) .f_tiles ) , ( (  i32_dash_size225 ) ( (  y2508 ) ) ) ) ) ,  ( (  i32_dash_size225 ) ( (  x2506 ) ) ) ) );
    (*  tp2511 ) = ( (  fun2510 ) ( ( * (  tp2511 ) ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   map_dash_tile649 (    struct TileMap_645  tilemap2504 ,    int32_t  x2506 ,    int32_t  y2508 ,    struct Tile_91 (*  fun2510 )(    struct Tile_91  ) ) {
    struct Tile_91 *  tp2511 = ( (  get_dash_ptr490 ) ( (  elem_dash_get511 ( ( (  tilemap2504 ) .f_tiles ) , ( (  i32_dash_size225 ) ( (  y2508 ) ) ) ) ) ,  ( (  i32_dash_size225 ) ( (  x2506 ) ) ) ) );
    (*  tp2511 ) = ( (  fun2510 ) ( ( * (  tp2511 ) ) ) );
    return ( Unit_141_Unit );
}

static  enum Unit_141   map_dash_tile650 (    struct TileMap_645  tilemap2504 ,    int32_t  x2506 ,    int32_t  y2508 ,    struct Tile_91 (*  fun2510 )(    struct Tile_91  ) ) {
    struct Tile_91 *  tp2511 = ( (  get_dash_ptr490 ) ( (  elem_dash_get511 ( ( (  tilemap2504 ) .f_tiles ) , ( (  i32_dash_size225 ) ( (  y2508 ) ) ) ) ) ,  ( (  i32_dash_size225 ) ( (  x2506 ) ) ) ) );
    (*  tp2511 ) = ( (  fun2510 ) ( ( * (  tp2511 ) ) ) );
    return ( Unit_141_Unit );
}

static  struct Maybe_276   lam417 (   struct env417 env ,    struct Slice_90  s2520 ) {
    return ( (  try_dash_get493 ) ( (  s2520 ) ,  ( env.x2517 ) ) );
}

static  struct Tile_91   elem_dash_get651 (    struct TileMap_645  self2514 ,    struct Tuple2_411  idx2516 ) {
    size_t  x2517 = ( (  i32_dash_size225 ) ( ( (  fst410 ) ( (  idx2516 ) ) ) ) );
    size_t  y2518 = ( (  i32_dash_size225 ) ( ( (  snd414 ) ( (  idx2516 ) ) ) ) );
    struct env417 envinst417 = {
        .x2517 =  x2517 ,
    };
    return ( (  or_dash_else489 ) ( ( (  and_dash_maybe416 ) ( ( (  try_dash_get492 ) ( ( (  self2514 ) .f_tiles ) ,  (  y2518 ) ) ) ,  ( (struct funenv417){ .fun = lam417, .env = envinst417 } ) ) ) ,  ( (struct Tile_91) { .f_is_dash_bomb = ( false ) , .f_hidden = ( false ) , .f_flagged = ( false ) } ) ) );
}

static  struct Tile_91   lam657 (    struct Tile_91  dref2537 ) {
    return ( (struct Tile_91) { .f_hidden = ( true ) , .f_is_dash_bomb = ( true ) , .f_flagged = ( false ) } );
}

static  struct TileMap_645   generate_dash_map652 (    size_t  w2523 ,    size_t  h2525 ,    int32_t  bombs2527 ,    enum CAllocator_331  al2529 ) {
    struct TileMap_645  tiles2530 = ( (  mk_dash_tiles644 ) ( (  w2523 ) ,  (  h2525 ) ,  (  al2529 ) ) );
    struct RangeIter_252  temp653 =  into_dash_iter251 ( ( (  to249 ) ( (  from_dash_integral2 ( 1 ) ) ,  (  bombs2527 ) ) ) );
    while (true) {
        struct Maybe_254  __cond654 =  next253 (&temp653);
        if (  __cond654 .tag == 0 ) {
            break;
        }
        int32_t  bomb2532 =  __cond654 .stuff .Maybe_254_Just_s .field0;
        int32_t  temp655;
        int32_t  x2533 = (  temp655 );
        int32_t  temp656;
        int32_t  y2534 = (  temp656 );
        while ( ( true ) ) {
            x2533 = ( (  u32_dash_i32232 ) ( ( (  mod419 ) ( ( (  next_dash_u32568 ) ( ) ) ,  ( (  size_dash_u32229 ) ( (  w2523 ) ) ) ) ) ) );
            y2534 = ( (  u32_dash_i32232 ) ( ( (  mod419 ) ( ( (  next_dash_u32568 ) ( ) ) ,  ( (  size_dash_u32229 ) ( (  h2525 ) ) ) ) ) ) );
            if ( ( ! ( (  elem_dash_get651 ( (  tiles2530 ) , ( ( Tuple2_411_Tuple2 ) ( (  x2533 ) ,  (  y2534 ) ) ) ) ) .f_is_dash_bomb ) ) ) {
                break;
            }
        }
        ( (  map_dash_tile648 ) ( (  tiles2530 ) ,  (  x2533 ) ,  (  y2534 ) ,  (  lam657 ) ) );
    }
    return (  tiles2530 );
}

static  int32_t   count_dash_neighbor_dash_bombs658 (    struct TileMap_645  tilemap2540 ,    int32_t  x2542 ,    int32_t  y2544 ) {
    int32_t  neighbors2545 = (  from_dash_integral2 ( 0 ) );
    struct RangeIter_252  temp659 =  into_dash_iter251 ( ( (  to249 ) ( (  op_dash_sub47 ( (  y2544 ) , (  from_dash_integral2 ( 1 ) ) ) ) ,  (  op_dash_add46 ( (  y2544 ) , (  from_dash_integral2 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_254  __cond660 =  next253 (&temp659);
        if (  __cond660 .tag == 0 ) {
            break;
        }
        int32_t  yy2547 =  __cond660 .stuff .Maybe_254_Just_s .field0;
        struct RangeIter_252  temp661 =  into_dash_iter251 ( ( (  to249 ) ( (  op_dash_sub47 ( (  x2542 ) , (  from_dash_integral2 ( 1 ) ) ) ) ,  (  op_dash_add46 ( (  x2542 ) , (  from_dash_integral2 ( 1 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_254  __cond662 =  next253 (&temp661);
            if (  __cond662 .tag == 0 ) {
                break;
            }
            int32_t  xx2549 =  __cond662 .stuff .Maybe_254_Just_s .field0;
            if ( ( (  elem_dash_get651 ( (  tilemap2540 ) , ( ( Tuple2_411_Tuple2 ) ( (  xx2549 ) ,  (  yy2547 ) ) ) ) ) .f_is_dash_bomb ) ) {
                neighbors2545 = (  op_dash_add46 ( (  neighbors2545 ) , (  from_dash_integral2 ( 1 ) ) ) );
            }
        }
    }
    return (  neighbors2545 );
}

static  enum Unit_141   render_dash_tiles663 (    struct Screen_330 *  screen2552 ,    struct TileMap_645  tilemap2905 ,    struct Tuple2_411  dref2906 ,    enum GameState_642  game_dash_state2910 ) {
    ( (  set_dash_screen_dash_bg629 ) ( (  screen2552 ) ,  ( ( Color_16_Color8 ) ( ( Color8_17_Magenta8 ) ) ) ) );
    struct RangeIter_252  temp664 =  into_dash_iter251 ( ( (  to249 ) ( (  op_dash_neg50 ( (  from_dash_integral2 ( 1 ) ) ) ) ,  ( (  tilemap2905 ) .f_width ) ) ) );
    while (true) {
        struct Maybe_254  __cond665 =  next253 (&temp664);
        if (  __cond665 .tag == 0 ) {
            break;
        }
        int32_t  x2912 =  __cond665 .stuff .Maybe_254_Just_s .field0;
        ( (  put_dash_char637 ) ( (  screen2552 ) ,  ( (  from_dash_charlike0 ) ( ( " " ) ) ) ,  (  op_dash_add46 ( (  x2912 ) , ( dref2906 .field0 ) ) ) ,  (  op_dash_sub47 ( ( dref2906 .field1 ) , (  from_dash_integral2 ( 1 ) ) ) ) ) );
        ( (  put_dash_char637 ) ( (  screen2552 ) ,  ( (  from_dash_charlike0 ) ( ( " " ) ) ) ,  (  op_dash_add46 ( (  x2912 ) , ( dref2906 .field0 ) ) ) ,  (  op_dash_add46 ( ( dref2906 .field1 ) , ( (  tilemap2905 ) .f_height ) ) ) ) );
    }
    struct RangeIter_252  temp666 =  into_dash_iter251 ( ( (  to249 ) ( (  from_dash_integral2 ( 0 ) ) ,  (  op_dash_sub47 ( ( (  tilemap2905 ) .f_height ) , (  from_dash_integral2 ( 1 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_254  __cond667 =  next253 (&temp666);
        if (  __cond667 .tag == 0 ) {
            break;
        }
        int32_t  y2914 =  __cond667 .stuff .Maybe_254_Just_s .field0;
        ( (  put_dash_char637 ) ( (  screen2552 ) ,  ( (  from_dash_charlike0 ) ( ( " " ) ) ) ,  (  op_dash_sub47 ( ( dref2906 .field0 ) , (  from_dash_integral2 ( 1 ) ) ) ) ,  (  op_dash_add46 ( (  y2914 ) , ( dref2906 .field1 ) ) ) ) );
        ( (  put_dash_char637 ) ( (  screen2552 ) ,  ( (  from_dash_charlike0 ) ( ( " " ) ) ) ,  (  op_dash_add46 ( ( dref2906 .field0 ) , ( (  tilemap2905 ) .f_width ) ) ) ,  (  op_dash_add46 ( (  y2914 ) , ( dref2906 .field1 ) ) ) ) );
    }
    struct Zip_260  temp668 =  into_dash_iter259 ( ( (  zip281 ) ( ( (  tilemap2905 ) .f_tiles ) ,  ( (  from255 ) ( (  from_dash_integral2 ( 0 ) ) ) ) ) ) );
    while (true) {
        struct Maybe_269  __cond669 =  next268 (&temp668);
        if (  __cond669 .tag == 0 ) {
            break;
        }
        struct Tuple2_270  dref2915 =  __cond669 .stuff .Maybe_269_Just_s .field0;
        struct Zip_264  temp670 =  into_dash_iter263 ( ( (  zip283 ) ( ( dref2915 .field0 ) ,  ( (  from255 ) ( (  from_dash_integral2 ( 0 ) ) ) ) ) ) );
        while (true) {
            struct Maybe_274  __cond671 =  next273 (&temp670);
            if (  __cond671 .tag == 0 ) {
                break;
            }
            struct Tuple2_275  dref2918 =  __cond671 .stuff .Maybe_274_Just_s .field0;
            int32_t  x2921 = (  op_dash_add46 ( ( dref2918 .field1 ) , ( dref2906 .field0 ) ) );
            int32_t  y2922 = (  op_dash_add46 ( ( dref2915 .field1 ) , ( dref2906 .field1 ) ) );
            struct Color_16  bg2923 = ( (  eq8 ( ( (  mod420 ) ( (  op_dash_add46 ( ( dref2918 .field1 ) , ( dref2915 .field1 ) ) ) ,  (  from_dash_integral2 ( 2 ) ) ) ) , (  from_dash_integral2 ( 0 ) ) ) ) ? ( ( Color_16_Color8 ) ( ( Color8_17_White8 ) ) ) : ( ( Color_16_Color16 ) ( ( Color16_18_BrightWhite16 ) ) ) );
            if ( ( ( dref2918 .field0 ) .f_hidden ) ) {
                ( (  set_dash_screen_dash_bg629 ) ( (  screen2552 ) ,  (  bg2923 ) ) );
                if ( ( ( dref2918 .field0 ) .f_flagged ) ) {
                    ( (  set_dash_screen_dash_fg628 ) ( (  screen2552 ) ,  ( ( Color_16_Color8 ) ( ( Color8_17_Blue8 ) ) ) ) );
                    ( (  put_dash_char637 ) ( (  screen2552 ) ,  ( (  from_dash_charlike0 ) ( ( "F" ) ) ) ,  (  x2921 ) ,  (  y2922 ) ) );
                } else {
                    ( (  put_dash_char637 ) ( (  screen2552 ) ,  ( (  from_dash_charlike0 ) ( ( " " ) ) ) ,  (  x2921 ) ,  (  y2922 ) ) );
                }
            } else {
                ( (  set_dash_screen_dash_colors630 ) ( (  screen2552 ) ,  ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) ,  ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) ) );
                int32_t  num_dash_bombs2924 = ( (  count_dash_neighbor_dash_bombs658 ) ( (  tilemap2905 ) ,  ( dref2918 .field1 ) ,  ( dref2915 .field1 ) ) );
                if ( (  eq8 ( (  num_dash_bombs2924 ) , (  from_dash_integral2 ( 0 ) ) ) ) ) {
                    ( (  put_dash_char637 ) ( (  screen2552 ) ,  ( (  from_dash_charlike0 ) ( ( " " ) ) ) ,  (  x2921 ) ,  (  y2922 ) ) );
                } else {
                    char  num_dash_bombs_dash_char2925 = ( (  or_dash_fail488 ) ( ( (  head402 ) ( ( (  chars425 ) ( (  num_dash_bombs2924 ) ) ) ) ) ,  ( "impossible:)" ) ) );
                    ( (  put_dash_char637 ) ( (  screen2552 ) ,  (  num_dash_bombs_dash_char2925 ) ,  (  x2921 ) ,  (  y2922 ) ) );
                }
            }
            if ( ( (  eq641 ( (  game_dash_state2910 ) , ( GameState_642_Failed ) ) ) && ( ( dref2918 .field0 ) .f_is_dash_bomb ) ) ) {
                if ( ( ( dref2918 .field0 ) .f_hidden ) ) {
                    ( (  set_dash_screen_dash_fg628 ) ( (  screen2552 ) ,  ( ( Color_16_Color8 ) ( ( Color8_17_Red8 ) ) ) ) );
                    ( (  set_dash_screen_dash_bg629 ) ( (  screen2552 ) ,  ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) ) );
                    ( (  put_dash_char637 ) ( (  screen2552 ) ,  ( (  from_dash_charlike0 ) ( ( "o" ) ) ) ,  (  x2921 ) ,  (  y2922 ) ) );
                } else {
                    ( (  set_dash_screen_dash_fg628 ) ( (  screen2552 ) ,  ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) ) );
                    ( (  set_dash_screen_dash_bg629 ) ( (  screen2552 ) ,  ( ( Color_16_Color8 ) ( ( Color8_17_Red8 ) ) ) ) );
                    ( (  put_dash_char637 ) ( (  screen2552 ) ,  ( (  from_dash_charlike0 ) ( ( "o" ) ) ) ,  (  x2921 ) ,  (  y2922 ) ) );
                }
            }
        }
    }
    return ( Unit_141_Unit );
}

static  bool   lam673 (    struct Tile_91  tile2930 ) {
    return ( ( ( (  tile2930 ) .f_is_dash_bomb ) && ( (  tile2930 ) .f_hidden ) ) || ( ( ! ( (  tile2930 ) .f_is_dash_bomb ) ) && ( ! ( (  tile2930 ) .f_hidden ) ) ) );
}

static  bool   is_dash_game_dash_won672 (    struct TileMap_645  tilemap2928 ) {
    return ( (  all397 ) ( ( (  flatten290 ) ( ( (  tilemap2928 ) .f_tiles ) ) ) ,  (  lam673 ) ) );
}

static  struct Tile_91   lam675 (    struct Tile_91  tile2940 ) {
    struct Tile_91  temp676 = (  tile2940 );
    temp676 .  f_hidden = ( false );
    return ( temp676 );
}

static  bool   uncover_dash_tile674 (    struct TileMap_645  tilemap2933 ,    int32_t  x2935 ,    int32_t  y2937 ) {
    if ( ( ( ( (  cmp39 ( (  x2935 ) , (  from_dash_integral2 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  x2935 ) , ( (  tilemap2933 ) .f_width ) ) != 0 ) ) || (  cmp39 ( (  y2937 ) , (  from_dash_integral2 ( 0 ) ) ) == 0 ) ) || (  cmp39 ( (  y2937 ) , ( (  tilemap2933 ) .f_height ) ) != 0 ) ) ) {
        return ( false );
    }
    struct Tile_91  tile2938 = (  elem_dash_get651 ( (  tilemap2933 ) , ( ( Tuple2_411_Tuple2 ) ( (  x2935 ) ,  (  y2937 ) ) ) ) );
    if ( ( ! ( (  tile2938 ) .f_hidden ) ) ) {
        return ( false );
    }
    ( (  map_dash_tile649 ) ( (  tilemap2933 ) ,  (  x2935 ) ,  (  y2937 ) ,  (  lam675 ) ) );
    if ( ( (  tile2938 ) .f_is_dash_bomb ) ) {
        return ( true );
    } else {
        int32_t  nb2941 = ( (  count_dash_neighbor_dash_bombs658 ) ( (  tilemap2933 ) ,  (  x2935 ) ,  (  y2937 ) ) );
        if ( (  eq8 ( (  nb2941 ) , (  from_dash_integral2 ( 0 ) ) ) ) ) {
            struct RangeIter_252  temp677 =  into_dash_iter251 ( ( (  to249 ) ( (  op_dash_sub47 ( (  y2937 ) , (  from_dash_integral2 ( 1 ) ) ) ) ,  (  op_dash_add46 ( (  y2937 ) , (  from_dash_integral2 ( 1 ) ) ) ) ) ) );
            while (true) {
                struct Maybe_254  __cond678 =  next253 (&temp677);
                if (  __cond678 .tag == 0 ) {
                    break;
                }
                int32_t  yy2943 =  __cond678 .stuff .Maybe_254_Just_s .field0;
                struct RangeIter_252  temp679 =  into_dash_iter251 ( ( (  to249 ) ( (  op_dash_sub47 ( (  x2935 ) , (  from_dash_integral2 ( 1 ) ) ) ) ,  (  op_dash_add46 ( (  x2935 ) , (  from_dash_integral2 ( 1 ) ) ) ) ) ) );
                while (true) {
                    struct Maybe_254  __cond680 =  next253 (&temp679);
                    if (  __cond680 .tag == 0 ) {
                        break;
                    }
                    int32_t  xx2945 =  __cond680 .stuff .Maybe_254_Just_s .field0;
                    ( (  uncover_dash_tile674 ) ( (  tilemap2933 ) ,  (  xx2945 ) ,  (  yy2943 ) ) );
                }
            }
        }
        return ( false );
    }
}

static  struct Tile_91   lam682 (    struct Tile_91  tile2954 ) {
    struct Tile_91  temp683 = (  tile2954 );
    temp683 .  f_flagged = ( ! ( (  tile2954 ) .f_flagged ) );
    return ( temp683 );
}

static  bool   toggle_dash_flag681 (    struct TileMap_645  tilemap2948 ,    int32_t  x2950 ,    int32_t  y2952 ) {
    if ( ( ( ( (  cmp39 ( (  x2950 ) , (  from_dash_integral2 ( 0 ) ) ) == 0 ) || (  cmp39 ( (  x2950 ) , ( (  tilemap2948 ) .f_width ) ) != 0 ) ) || (  cmp39 ( (  y2952 ) , (  from_dash_integral2 ( 0 ) ) ) == 0 ) ) || (  cmp39 ( (  y2952 ) , ( (  tilemap2948 ) .f_height ) ) != 0 ) ) ) {
        return ( false );
    }
    ( (  map_dash_tile650 ) ( (  tilemap2948 ) ,  (  x2950 ) ,  (  y2952 ) ,  (  lam682 ) ) );
}

static  struct Tuple2_411   get_dash_board_dash_off684 (    struct Tui_332 *  tui2957 ,    struct TileMap_645  tilemap2959 ) {
    return ( ( Tuple2_411_Tuple2 ) ( (  op_dash_sub47 ( (  op_dash_div49 ( ( (  u32_dash_i32232 ) ( ( ( * (  tui2957 ) ) .f_width ) ) ) , (  from_dash_integral2 ( 2 ) ) ) ) , (  op_dash_div49 ( ( (  tilemap2959 ) .f_width ) , (  from_dash_integral2 ( 2 ) ) ) ) ) ) ,  (  op_dash_sub47 ( (  op_dash_div49 ( ( (  u32_dash_i32232 ) ( ( ( * (  tui2957 ) ) .f_height ) ) ) , (  from_dash_integral2 ( 2 ) ) ) ) , (  op_dash_div49 ( ( (  tilemap2959 ) .f_height ) , (  from_dash_integral2 ( 2 ) ) ) ) ) ) ) );
}

struct funenv587 {
    struct Tui_332  (*fun) (  struct env587  );
    struct env587 env;
};

struct funenv626 {
    bool  (*fun) (  struct env626  ,    struct Screen_330 *  );
    struct env626 env;
};

int main(int argc, const char **argv) {
	_global_argc = argc; _global_argv = argv;
    size_t  starting_dash_size1885 = ( (  from_dash_integral7 ( 8 ) ) );
    size_t  growth_dash_factor1886 = ( (  from_dash_integral7 ( 2 ) ) );
    size_t  shrink_dash_factor1887 = ( (  from_dash_integral7 ( 8 ) ) );
    ( ( srand ) ( ( (  cast148 ) ( ( ( time ) ( ( (  null_dash_c_dash_ptr218 ) ( ) ) ) ) ) ) ) );
    bool  temp586 = ( true );
    bool *  should_dash_resize2676 = ( &temp586 );
    struct env587 envinst587 = {
        .should_dash_resize2676 =  should_dash_resize2676 ,
    };
    struct env611 envinst611 = {
        .should_dash_resize2676 =  should_dash_resize2676 ,
    };
    struct env626 envinst626 = {
        .envinst611 = envinst611 ,
    };
    struct Slice_503  args2962 = ( (  get640 ) ( ) );
    size_t  width2963 = (  from_dash_integral7 ( 9 ) );
    size_t  height2964 = (  from_dash_integral7 ( 9 ) );
    int32_t  bombs2965 = (  from_dash_integral2 ( 10 ) );
    struct Slice_503  dref2966 = (  args2962 );
    const char*  __larr__685[3];
    const char*  *dref2967 =  __larr__685;
    if (  deconstruct515 (  dref2966 , &  dref2967 , 3 , (   struct ListSpread_516  ) { .tag = 0 } , NULL , 0 ) ) {
        width2963 = ( (  i64_dash_size227 ) ( ( (  or_dash_fail478 ) ( ( (  parse_dash_int538 ) ( ( dref2967[0] ) ) ) ,  ( "could not parse width" ) ) ) ) );
        height2964 = ( (  i64_dash_size227 ) ( ( (  or_dash_fail478 ) ( ( (  parse_dash_int538 ) ( ( dref2967[1] ) ) ) ,  ( "could not parse height" ) ) ) ) );
        bombs2965 = ( (  i64_dash_i32226 ) ( ( (  or_dash_fail478 ) ( ( (  parse_dash_int538 ) ( ( dref2967[2] ) ) ) ,  ( "could not parse bombs" ) ) ) ) );
    }
    else {
        const char*  *dref2971 = NULL;
        if (  deconstruct515 (  dref2966 , &  dref2971 , 0 , (   struct ListSpread_516  ) { .tag = 0 } , NULL , 0 ) ) {
        }
        else {
            if ( true ) {
                ( (  panic474 ) ( ( "args??" ) ) );
            }
        }
    }
    enum GameState_642  game_dash_state2972 = ( GameState_642_InProgress );
    enum CAllocator_331  al2973 = ( (  idc522 ) ( ) );
    struct TileMap_645  tilemap2974 = ( (  generate_dash_map652 ) ( (  width2963 ) ,  (  height2964 ) ,  (  bombs2965 ) ,  (  al2973 ) ) );
    struct funenv587  temp688 = ( (struct funenv587){ .fun = mk587, .env =  envinst587  } );
    struct Tui_332  temp687 = ( temp688.fun ( temp688.env ) );
    struct Tui_332 *  tui2975 = ( &temp687 );
    enum CAllocator_331  al2976 = ( (  idc522 ) ( ) );
    struct Screen_330  temp689 = ( (  mk_dash_screen612 ) ( (  tui2975 ) ,  (  al2976 ) ) );
    struct Screen_330 *  screen2977 = ( &temp689 );
    bool  running2978 = ( true );
    while ( (  running2978 ) ) {
        bool  needs_dash_redraw2979 = ( false );
        struct FunIter_299  temp690 =  into_dash_iter298 ( ( (  from_dash_function305 ) ( (  read_dash_key605 ) ) ) );
        while (true) {
            struct Maybe_300  __cond691 =  next304 (&temp690);
            if (  __cond691 .tag == 0 ) {
                break;
            }
            struct InputEvent_301  ev2981 =  __cond691 .stuff .Maybe_300_Just_s .field0;
            needs_dash_redraw2979 = ( true );
            struct funenv611  temp692 = ( (struct funenv611){ .fun = update_dash_dimensions611, .env =  envinst611  } );
            ( temp692.fun ( temp692.env ,  (  tui2975 ) ) );
            struct InputEvent_301  dref2982 = (  ev2981 );
            if ( dref2982.tag == InputEvent_301_Key_t && dref2982 .stuff .InputEvent_301_Key_s .field0.tag == Key_302_Char_t ) {
                if ( (  eq13 ( ( dref2982 .stuff .InputEvent_301_Key_s .field0 .stuff .Key_302_Char_s .field0 ) , ( (  from_dash_charlike0 ) ( ( "q" ) ) ) ) ) ) {
                    running2978 = ( false );
                }
                if ( (  eq13 ( ( dref2982 .stuff .InputEvent_301_Key_s .field0 .stuff .Key_302_Char_s .field0 ) , ( (  from_dash_charlike0 ) ( ( "r" ) ) ) ) ) ) {
                    tilemap2974 = ( (  generate_dash_map652 ) ( (  width2963 ) ,  (  height2964 ) ,  (  bombs2965 ) ,  (  al2976 ) ) );
                    game_dash_state2972 = ( GameState_642_InProgress );
                }
            }
            else {
                if ( dref2982.tag == InputEvent_301_Mouse_t ) {
                    int32_t  x2985 = (  op_dash_sub47 ( ( ( dref2982 .stuff .InputEvent_301_Mouse_s .field0 ) .f_x ) , ( (  fst410 ) ( ( (  get_dash_board_dash_off684 ) ( (  tui2975 ) ,  (  tilemap2974 ) ) ) ) ) ) );
                    int32_t  y2986 = (  op_dash_sub47 ( ( ( dref2982 .stuff .InputEvent_301_Mouse_s .field0 ) .f_y ) , ( (  snd414 ) ( ( (  get_dash_board_dash_off684 ) ( (  tui2975 ) ,  (  tilemap2974 ) ) ) ) ) ) );
                    if ( ( (  eq598 ( ( ( dref2982 .stuff .InputEvent_301_Mouse_s .field0 ) .f_button ) , ( MouseButton_106_MouseLeft ) ) ) && ( ( dref2982 .stuff .InputEvent_301_Mouse_s .field0 ) .f_pressed ) ) ) {
                        if ( (  eq641 ( (  game_dash_state2972 ) , ( GameState_642_InProgress ) ) ) ) {
                            if ( ( ( ! ( (  elem_dash_get651 ( (  tilemap2974 ) , ( ( Tuple2_411_Tuple2 ) ( (  x2985 ) ,  (  y2986 ) ) ) ) ) .f_flagged ) ) && ( (  uncover_dash_tile674 ) ( (  tilemap2974 ) ,  (  x2985 ) ,  (  y2986 ) ) ) ) ) {
                                game_dash_state2972 = ( GameState_642_Failed );
                            }
                            if ( ( (  eq641 ( (  game_dash_state2972 ) , ( GameState_642_InProgress ) ) ) && ( (  is_dash_game_dash_won672 ) ( (  tilemap2974 ) ) ) ) ) {
                                game_dash_state2972 = ( GameState_642_Won );
                            }
                        }
                    }
                    if ( ( (  eq598 ( ( ( dref2982 .stuff .InputEvent_301_Mouse_s .field0 ) .f_button ) , ( MouseButton_106_MouseRight ) ) ) && ( ( dref2982 .stuff .InputEvent_301_Mouse_s .field0 ) .f_pressed ) ) ) {
                        if ( (  eq641 ( (  game_dash_state2972 ) , ( GameState_642_InProgress ) ) ) ) {
                            ( (  toggle_dash_flag681 ) ( (  tilemap2974 ) ,  (  x2985 ) ,  (  y2986 ) ) );
                        }
                    }
                }
            }
        }
        struct funenv626  temp693 = ( (struct funenv626){ .fun = resize_dash_screen_dash_if_dash_needed626, .env =  envinst626  } );
        if ( ( temp693.fun ( temp693.env ,  (  screen2977 ) ) ) ) {
            needs_dash_redraw2979 = ( true );
        }
        if ( (  needs_dash_redraw2979 ) ) {
            ( (  clear_dash_screen616 ) ( (  screen2977 ) ) );
            ( (  set_dash_screen_dash_colors630 ) ( (  screen2977 ) ,  ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) ,  ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) ) );
            ( (  fill_dash_default632 ) ( (  screen2977 ) ) );
            ( (  render_dash_tiles663 ) ( (  screen2977 ) ,  (  tilemap2974 ) ,  ( (  get_dash_board_dash_off684 ) ( (  tui2975 ) ,  (  tilemap2974 ) ) ) ,  (  game_dash_state2972 ) ) );
            ( (  set_dash_screen_dash_colors630 ) ( (  screen2977 ) ,  ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) ,  ( (struct Color_16) { .tag = Color_16_ColorDefault_t } ) ) );
            if ( (  eq641 ( (  game_dash_state2972 ) , ( GameState_642_Failed ) ) ) ) {
                ( (  draw_dash_str_dash_center639 ) ( (  screen2977 ) ,  ( "ya failed. restart? (r)" ) ,  (  op_dash_div49 ( ( (  u32_dash_i32232 ) ( ( ( * (  tui2975 ) ) .f_width ) ) ) , (  from_dash_integral2 ( 2 ) ) ) ) ,  (  op_dash_add46 ( (  op_dash_add46 ( ( (  tilemap2974 ) .f_height ) , ( (  snd414 ) ( ( (  get_dash_board_dash_off684 ) ( (  tui2975 ) ,  (  tilemap2974 ) ) ) ) ) ) ) , (  from_dash_integral2 ( 2 ) ) ) ) ) );
            } else {
                if ( (  eq641 ( (  game_dash_state2972 ) , ( GameState_642_Won ) ) ) ) {
                    ( (  draw_dash_str_dash_center639 ) ( (  screen2977 ) ,  ( "ya won. quit? (q)" ) ,  (  op_dash_div49 ( ( (  u32_dash_i32232 ) ( ( ( * (  tui2975 ) ) .f_width ) ) ) , (  from_dash_integral2 ( 2 ) ) ) ) ,  (  op_dash_add46 ( (  op_dash_add46 ( ( (  tilemap2974 ) .f_height ) , ( (  snd414 ) ( ( (  get_dash_board_dash_off684 ) ( (  tui2975 ) ,  (  tilemap2974 ) ) ) ) ) ) ) , (  from_dash_integral2 ( 2 ) ) ) ) ) );
                }
            }
            ( (  render_dash_screen620 ) ( (  screen2977 ) ) );
        }
        ( (  sync593 ) ( (  tui2975 ) ) );
    }
    ( (  free_dash_screen615 ) ( (  screen2977 ) ) );
    ( (  deinit597 ) ( (  tui2975 ) ) );
}
