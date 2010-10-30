/* Contributed by Nicola Pero <nicola.pero@meta-innovation.com>, October 2010.  */
/* { dg-do run } */

/* Test the property syntax with synthesized setter/getter
   and with a non-standard name for the getter and setter.  */

#include <stdlib.h>
#include <objc/objc.h>
#include <objc/runtime.h>

@interface MyRootClass
{
  Class isa;
  int a;
}
@property (getter = giveMeA, setter = writeA:) int a;
+ (id) initialize;
+ (id) alloc;
- (id) init;
@end

@implementation MyRootClass
+ (id) initialize { return self; }
+ (id) alloc { return class_createInstance (self, 0); }
- (id) init { return self; }
@synthesize a;
@end

int main (void)
{
  MyRootClass *object = [[MyRootClass alloc] init];

  object.a = 14;

  if (object.a != 14)
    abort ();

  object.a = 23;

  if (object.a != 23)
    abort ();

  object.a = 78;

  if (object.a != 78)
    abort ();

  return (0);
}
