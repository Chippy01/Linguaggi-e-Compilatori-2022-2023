; ModuleID = 'test/test.optSR.bc'
source_filename = "test/test.ll"

define dso_local void @foo(i32 noundef %0) {
  %2 = add nsw i32 %0, 0
  %3 = mul nsw i32 %2, 16
  %4 = shl i32 %2, 4
  %5 = mul nsw i32 %4, %2
  %6 = sdiv i32 %5, %0
  %7 = sdiv i32 %5, 10
  %8 = mul nsw i32 1, %6
  %9 = shl i32 %6, 0
  %10 = sdiv i32 %7, 128
  %11 = lshr i32 %7, 7
  %12 = sdiv i32 %9, 54
  %13 = sdiv i32 %7, 1
  %14 = lshr i32 %7, 0
  %15 = sub nsw i32 %12, 0
  %16 = mul nsw i32 %15, 15
  %17 = shl i32 %15, 4
  %18 = sub i32 %17, %15
  %19 = add nsw i32 %18, 3
  ret void
}
