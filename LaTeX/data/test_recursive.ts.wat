(module
  (type $t0 (func (param i32) (result i32)))
  (func $run (export "run") (type $t0) (param $p0 i32) (result i32)
    (if $I0(*\label{r-wat:if_block}*)
      (i32.lt_s
        (local.get $p0)
        (i32.const 2))
      (then(*\label{r-wat:then}*)
        (return
          (local.get $p0))))
    (i32.add
      (call $run
        (i32.sub(*\label{r-wat:sub}*)
          (local.get $p0)
          (i32.const 1)))
      (call $run
        (i32.sub
          (local.get $p0)
          (i32.const 2)))))