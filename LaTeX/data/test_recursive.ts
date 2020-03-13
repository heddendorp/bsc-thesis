export function run(n: i32): i32 {
  if(n < 2 ) {
    return n;
  }
  return run(n - 1) + run(n - 2);
}
