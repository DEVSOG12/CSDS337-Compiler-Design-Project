; ModuleID = 'TestMod'
source_filename = "TestMod"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(ptr, ...)

define void @main() {
entry:
  br label %whileLoop

whileLoop:                                        ; preds = %whileLoopBody, %entry
  %i.0 = phi i32 [ 0, %entry ], [ %1, %whileLoopBody ]
  %0 = icmp slt i32 %i.0, 10
  br i1 %0, label %whileLoopBody, label %whileLoopEnd

whileLoopBody:                                    ; preds = %whileLoop
  %1 = add i32 %i.0, 1
  %2 = call i32 (ptr, ...) @printf(ptr @0, i32 %1)
  br label %whileLoop

whileLoopEnd:                                     ; preds = %whileLoop
  ret void
}
