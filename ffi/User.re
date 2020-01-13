open Ctypes
open Foreign

type t = ptr(unit);
let t = ptr(void);

/* TODO: force static linking */
external placeholder: unit => unit = "create_user";

let c_create = foreign("create_user", int32_t @-> string @-> returning(t));
let c_name = foreign("get_user_name", t @-> returning(string));
let c_free = foreign("free_user", t @-> returning(void));
let c_strlen = foreign("strlen", ptr(char) @-> returning(size_t));

let finalise = t => {
  Gc.finalise(c_free, t);
  t;
};

let create = (id, name) => c_create(id, name) |> finalise;
let name = t => c_name(t);