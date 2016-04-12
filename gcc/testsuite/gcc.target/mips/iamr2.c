/* { dg-options "-march=interaptiv-mr2 -mno-abicalls -mgpopt -G8 -mabi=32 -mips16 -mmips16e2 -mno-memcpy" } */

/* Test UCOPYW.  */

/* { dg-final { scan-assembler "test01:.*\tucopyw\t.*test01\n" } } */
/* { dg-final { scan-assembler-times "\tucopyw\t" 1 } } */
struct node01
{
  short i;
  short j;
  short k;
  short l;
  short a;
  short b;
  short c;
  short d;
} __attribute__ ((packed));

struct node01 dst01 __attribute__((aligned(2)));
struct node01 src01 __attribute__((aligned(2)));

void
test01 (void)
{
  dst01 = src01;
}

/* Test COPYW.  */

/* { dg-final { scan-assembler "test02:.*\tcopyw\t.*\tcopyw\t.*test02\n" } } */
/* { dg-final { scan-assembler-times "\tcopyw\t" 2 } } */
struct node02
{
  int i;
  int j;
  int k;
  int l;
  int a;
  int b;
  int c;
  int d;
};

struct node02 dst02;
struct node02 src02;

void
test02 (void)
{
  dst02 = src02;
}
