(func $run (export "run") (type $t1) (param $p0 i32) (result i32)
  (block $B0
    (br_if $B0
      (i32.lt_u
        (local.get $p0)
        (i32.const 2)))
    (return
      (i32.add
        (call $run
          (i32.add
            (local.get $p0)
            (i32.const -1)))
        (call $run
          (i32.add
            (local.get $p0)
            (i32.const -2))))))
  (local.get $p0))