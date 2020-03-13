(module
 (type $i32_=>_i32 (func (param i32) (result i32)))
 (memory $0 0)
 (export "memory" (memory $0))
 (export "run" (func $assembly/index/run))
 (func $assembly/index/run (; 0 ;) (param $0 i32) (result i32)
  local.get $0
  i32.const 2
  i32.lt_s
  if
   local.get $0
   return
  end
  local.get $0
  i32.const 1
  i32.sub
  call $assembly/index/run
  local.get $0
  i32.const 2
  i32.sub
  call $assembly/index/run
  i32.add
 )
)
