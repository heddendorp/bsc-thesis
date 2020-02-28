  (func $run (export "run") (type $t1) (param $p0 i32) (result i32)
    block $B0
      local.get $p0
      i32.const 2
      i32.lt_u
      br_if $B0
      local.get $p0
      i32.const -1
      i32.add
      call $run
      local.get $p0
      i32.const -2
      i32.add
      call $run
      i32.add
      return
    end
    local.get $p0)