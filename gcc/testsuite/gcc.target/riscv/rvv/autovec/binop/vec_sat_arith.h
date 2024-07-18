#ifndef HAVE_VEC_SAT_ARITH
#define HAVE_VEC_SAT_ARITH

#include <stdint-gcc.h>
#include <stdbool.h>

#define VALIDATE_RESULT(out, expect, N)              \
  do                                                 \
    {                                                \
      for (unsigned i = 0; i < N; i++)               \
        if (out[i] != expect[i]) __builtin_abort (); \
    }                                                \
  while (false)

/******************************************************************************/
/* Saturation Add (unsigned and signed)                                       */
/******************************************************************************/
#define DEF_VEC_SAT_U_ADD_FMT_1(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_add_##T##_fmt_1 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      out[i] = (x + y) | (-(T)((T)(x + y) < x));                     \
    }                                                                \
}

#define DEF_VEC_SAT_U_ADD_FMT_2(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_add_##T##_fmt_2 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      out[i] = (T)(x + y) >= x ? (x + y) : -1;                       \
    }                                                                \
}

#define DEF_VEC_SAT_U_ADD_FMT_3(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_add_##T##_fmt_3 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      T ret;                                                         \
      T overflow = __builtin_add_overflow (x, y, &ret);              \
      out[i] = (T)(-overflow) | ret;                                 \
    }                                                                \
}

#define DEF_VEC_SAT_U_ADD_FMT_4(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_add_##T##_fmt_4 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      T ret;                                                         \
      out[i] = __builtin_add_overflow (x, y, &ret) ? -1 : ret;       \
    }                                                                \
}

#define DEF_VEC_SAT_U_ADD_FMT_5(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_add_##T##_fmt_5 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      T ret;                                                         \
      out[i] = __builtin_add_overflow (x, y, &ret) == 0 ? ret : -1;  \
    }                                                                \
}

#define DEF_VEC_SAT_U_ADD_FMT_6(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_add_##T##_fmt_6 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      out[i] = x <= (T)(x + y) ? (x + y) : -1;                       \
    }                                                                \
}

#define DEF_VEC_SAT_U_ADD_FMT_7(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_add_##T##_fmt_7 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      out[i] = (T)(x + y) < x ? -1 : (x + y);                        \
    }                                                                \
}

#define DEF_VEC_SAT_U_ADD_FMT_8(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_add_##T##_fmt_8 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      out[i] = x > (T)(x + y) ? -1 : (x + y);                        \
    }                                                                \
}

#define RUN_VEC_SAT_U_ADD_FMT_1(T, out, op_1, op_2, N) \
  vec_sat_u_add_##T##_fmt_1(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_ADD_FMT_2(T, out, op_1, op_2, N) \
  vec_sat_u_add_##T##_fmt_2(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_ADD_FMT_3(T, out, op_1, op_2, N) \
  vec_sat_u_add_##T##_fmt_3(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_ADD_FMT_4(T, out, op_1, op_2, N) \
  vec_sat_u_add_##T##_fmt_4(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_ADD_FMT_5(T, out, op_1, op_2, N) \
  vec_sat_u_add_##T##_fmt_5(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_ADD_FMT_6(T, out, op_1, op_2, N) \
  vec_sat_u_add_##T##_fmt_6(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_ADD_FMT_7(T, out, op_1, op_2, N) \
  vec_sat_u_add_##T##_fmt_7(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_ADD_FMT_8(T, out, op_1, op_2, N) \
  vec_sat_u_add_##T##_fmt_8(out, op_1, op_2, N)

#define DEF_VEC_SAT_U_ADD_IMM_FMT_1(T, IMM)                          \
T __attribute__((noinline))                                          \
vec_sat_u_add_imm##IMM##_##T##_fmt_1 (T *out, T *in, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    out[i] = (T)(in[i] + IMM) >= in[i] ? (in[i] + IMM) : -1;         \
}
#define DEF_VEC_SAT_U_ADD_IMM_FMT_1_WRAP(T, IMM) \
  DEF_VEC_SAT_U_ADD_IMM_FMT_1(T, IMM)

#define DEF_VEC_SAT_U_ADD_IMM_FMT_2(T, IMM)                          \
T __attribute__((noinline))                                          \
vec_sat_u_add_imm##IMM##_##T##_fmt_2 (T *out, T *in, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    out[i] = (T)(in[i] + IMM) < in[i] ? -1 : (in[i] + IMM);          \
}
#define DEF_VEC_SAT_U_ADD_IMM_FMT_2_WRAP(T, IMM) \
  DEF_VEC_SAT_U_ADD_IMM_FMT_2(T, IMM)

#define RUN_VEC_SAT_U_ADD_IMM_FMT_1(T, out, op_1, expect, IMM, N) \
  vec_sat_u_add_imm##IMM##_##T##_fmt_1(out, op_1, N);             \
  VALIDATE_RESULT (out, expect, N)
#define RUN_VEC_SAT_U_ADD_IMM_FMT_1_WRAP(T, out, op_1, expect, IMM, N) \
  RUN_VEC_SAT_U_ADD_IMM_FMT_1(T, out, op_1, expect, IMM, N)

#define RUN_VEC_SAT_U_ADD_IMM_FMT_2(T, out, op_1, expect, IMM, N) \
  vec_sat_u_add_imm##IMM##_##T##_fmt_2(out, op_1, N);             \
  VALIDATE_RESULT (out, expect, N)
#define RUN_VEC_SAT_U_ADD_IMM_FMT_2_WRAP(T, out, op_1, expect, IMM, N) \
  RUN_VEC_SAT_U_ADD_IMM_FMT_2(T, out, op_1, expect, IMM, N)

/******************************************************************************/
/* Saturation Sub (Unsigned and Signed)                                       */
/******************************************************************************/
#define DEF_VEC_SAT_U_SUB_FMT_1(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_sub_##T##_fmt_1 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      out[i] = (x - y) & (-(T)(x >= y));                             \
    }                                                                \
}

#define DEF_VEC_SAT_U_SUB_FMT_2(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_sub_##T##_fmt_2 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      out[i] = (x - y) & (-(T)(x > y));                              \
    }                                                                \
}

#define DEF_VEC_SAT_U_SUB_FMT_3(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_sub_##T##_fmt_3 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      out[i] = x > y ? x - y : 0;                                    \
    }                                                                \
}

#define DEF_VEC_SAT_U_SUB_FMT_4(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_sub_##T##_fmt_4 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      out[i] = x >= y ? x - y : 0;                                   \
    }                                                                \
}

#define DEF_VEC_SAT_U_SUB_FMT_5(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_sub_##T##_fmt_5 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      out[i] = x < y ? 0 : x - y;                                    \
    }                                                                \
}

#define DEF_VEC_SAT_U_SUB_FMT_6(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_sub_##T##_fmt_6 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      out[i] = x <= y ? 0 : x - y;                                   \
    }                                                                \
}

#define DEF_VEC_SAT_U_SUB_FMT_7(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_sub_##T##_fmt_7 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      T ret;                                                         \
      T overflow = __builtin_sub_overflow (x, y, &ret);              \
      out[i] = ret & (T)(overflow - 1);                              \
    }                                                                \
}

#define DEF_VEC_SAT_U_SUB_FMT_8(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_sub_##T##_fmt_8 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      T ret;                                                         \
      T overflow = __builtin_sub_overflow (x, y, &ret);              \
      out[i] = ret & (T)-(!overflow);                                \
    }                                                                \
}

#define DEF_VEC_SAT_U_SUB_FMT_9(T)                                   \
void __attribute__((noinline))                                       \
vec_sat_u_sub_##T##_fmt_9 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      T x = op_1[i];                                                 \
      T y = op_2[i];                                                 \
      T ret;                                                         \
      bool overflow = __builtin_sub_overflow (x, y, &ret);           \
      out[i] = overflow ? 0 : ret;                                   \
    }                                                                \
}

#define DEF_VEC_SAT_U_SUB_FMT_10(T)                                   \
void __attribute__((noinline))                                        \
vec_sat_u_sub_##T##_fmt_10 (T *out, T *op_1, T *op_2, unsigned limit) \
{                                                                     \
  unsigned i;                                                         \
  for (i = 0; i < limit; i++)                                         \
    {                                                                 \
      T x = op_1[i];                                                  \
      T y = op_2[i];                                                  \
      T ret;                                                          \
      bool overflow = __builtin_sub_overflow (x, y, &ret);            \
      out[i] = !overflow ? ret : 0;                                   \
    }                                                                 \
}

#define DEF_VEC_SAT_U_SUB_ZIP(T1, T2)                             \
void __attribute__((noinline))                                    \
vec_sat_u_sub_##T1##_##T2##_fmt_zip (T1 *x, T2 b, unsigned limit) \
{                                                                 \
  T2 a;                                                           \
  T1 *p = x;                                                      \
  do {                                                            \
    a = *--p;                                                     \
    *p = (T1)(a >= b ? a - b : 0);                                \
  } while (--limit);                                              \
}
#define DEF_VEC_SAT_U_SUB_ZIP_WRAP(T1, T2) DEF_VEC_SAT_U_SUB_ZIP(T1, T2)

#define RUN_VEC_SAT_U_SUB_FMT_1(T, out, op_1, op_2, N) \
  vec_sat_u_sub_##T##_fmt_1(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_SUB_FMT_2(T, out, op_1, op_2, N) \
  vec_sat_u_sub_##T##_fmt_2(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_SUB_FMT_3(T, out, op_1, op_2, N) \
  vec_sat_u_sub_##T##_fmt_3(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_SUB_FMT_4(T, out, op_1, op_2, N) \
  vec_sat_u_sub_##T##_fmt_4(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_SUB_FMT_5(T, out, op_1, op_2, N) \
  vec_sat_u_sub_##T##_fmt_5(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_SUB_FMT_6(T, out, op_1, op_2, N) \
  vec_sat_u_sub_##T##_fmt_6(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_SUB_FMT_7(T, out, op_1, op_2, N) \
  vec_sat_u_sub_##T##_fmt_7(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_SUB_FMT_8(T, out, op_1, op_2, N) \
  vec_sat_u_sub_##T##_fmt_8(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_SUB_FMT_9(T, out, op_1, op_2, N) \
  vec_sat_u_sub_##T##_fmt_9(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_SUB_FMT_10(T, out, op_1, op_2, N) \
  vec_sat_u_sub_##T##_fmt_10(out, op_1, op_2, N)

#define RUN_VEC_SAT_U_SUB_FMT_ZIP(T1, T2, x, b, N) \
  vec_sat_u_sub_##T1##_##T2##_fmt_zip(x, b, N)
#define RUN_VEC_SAT_U_SUB_FMT_ZIP_WRAP(T1, T2, x, b, N) \
  RUN_VEC_SAT_U_SUB_FMT_ZIP(T1, T2, x, b, N) \

/******************************************************************************/
/* Saturation Sub Truncated (Unsigned and Signed)                             */
/******************************************************************************/
#define DEF_VEC_SAT_U_SUB_TRUNC_FMT_1(OUT_T, IN_T)                   \
void __attribute__((noinline))                                       \
vec_sat_u_sub_trunc_##OUT_T##_fmt_1 (OUT_T *out, IN_T *op_1, IN_T y, \
				     unsigned limit)                 \
{                                                                    \
  unsigned i;                                                        \
  for (i = 0; i < limit; i++)                                        \
    {                                                                \
      IN_T x = op_1[i];                                              \
      out[i] = (OUT_T)(x >= y ? x - y : 0);                          \
    }                                                                \
}

#define RUN_VEC_SAT_U_SUB_TRUNC_FMT_1(OUT_T, IN_T, out, op_1, y, N) \
  vec_sat_u_sub_trunc_##OUT_T##_fmt_1(out, op_1, y, N)

/******************************************************************************/
/* Saturation Truncation (Unsigned and Signed)                                */
/******************************************************************************/
#define DEF_VEC_SAT_U_TRUNC_FMT_1(NT, WT)                             \
void __attribute__((noinline))                                        \
vec_sat_u_trunc_##NT##_##WT##_fmt_1 (NT *out, WT *in, unsigned limit) \
{                                                                     \
  unsigned i;                                                         \
  for (i = 0; i < limit; i++)                                         \
    {                                                                 \
      WT x = in[i];                                                   \
      bool overflow = x > (WT)(NT)(-1);                               \
      out[i] = ((NT)x) | (NT)-overflow;                               \
    }                                                                 \
}
#define DEF_VEC_SAT_U_TRUNC_FMT_1_WRAP(NT, WT) DEF_VEC_SAT_U_TRUNC_FMT_1(NT, WT)

#define RUN_VEC_SAT_U_TRUNC_FMT_1(NT, WT, out, in, N) \
  vec_sat_u_trunc_##NT##_##WT##_fmt_1 (out, in, N)
#define RUN_VEC_SAT_U_TRUNC_FMT_1_WRAP(NT, WT, out, in, N) \
  RUN_VEC_SAT_U_TRUNC_FMT_1(NT, WT, out, in, N)

#endif
