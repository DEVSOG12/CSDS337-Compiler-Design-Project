; ModuleID = 'TestMod'
source_filename = "TestMod"

@0 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

declare i32 @printf(ptr, ...)

define void @main() {
entry:
  %0 = call i32 (ptr, ...) @printf(ptr @0, double -3.300000e+00)
  ret void
}
