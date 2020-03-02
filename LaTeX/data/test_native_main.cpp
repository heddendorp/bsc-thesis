int64_t native_timestamp;(*\label{n-wat:global}*)

m3ApiRawFunction(m3_thesis_mark) {(*\label{n-wat:mark_link}*)
    native_timestamp = esp_timer_get_time();
    m3ApiSuccess();
}

M3Result LinkThesis(IM3Runtime runtime) {
    IM3Module module = runtime->modules;
    const char *thesis = "thesis";

    m3_LinkRawFunction(module, thesis, "mark", "i()", &m3_thesis_mark);(*\label{n-wat:link}*)
    return m3Err_none;
}

void mark() {(*\label{n-wat:mark_native}*)
    native_timestamp = esp_timer_get_time();
}