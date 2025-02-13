use crate::{c_int, c_void};

use bridge_abi;

#[no_mangle]
pub extern "C" fn rs_loader_impl_destroy(loader_impl: *mut c_void) -> c_int {
    let loader_lifecycle_state = bridge_abi::get_loader_lifecycle_state(loader_impl);

    unsafe {
        loader_lifecycle_state.drop_in_place();
    }

    0 as c_int
}
