(module
  (type $t0 (func))
  (type $t1 (func (param i32)))
  (import "thesis" "mark" (func $thesis.mark (type $t0)))(*\label{n-wat:import}*)
  (func $run (export "run") (type $t1) (param $p0 i32)
    (call $thesis.mark)))(*\label{n-wat:call}*)