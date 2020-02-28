(module
  (type $t1 (func (param i32) (result i32)))
  (func $run (export "run") (type $t1) (param $p0 i32) (result i32)(*\label{r-wat:func}*)
    (block $B0(*\label{r-wat:block}*)
      (br_if $B0(*\label{r-wat:if}*)
        (i32.lt_u
          (local.get $p0)
          (i32.const 2)))
      (return(*\label{r-wat:return}*)
        (i32.add
          (call $run(*\label{r-wat:call1}*)
            (i32.add
              (local.get $p0)
              (i32.const -1)))
          (call $run(*\label{r-wat:call2}*)
            (i32.add
              (local.get $p0)
              (i32.const -2))))))
    (local.get $p0)))(*\label{r-wat:end}*)