open Ctypes
open Foreign

let () = FFI.User.({
  let user = create(Int32.of_int(1), "EduardoRFS");
  name(user) |> Console.log;
  Gc.full_major();
});