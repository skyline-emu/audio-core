A cut down version of *yuzu*'s `src/common` folder reimplementing functionality used by the audio renderer with reimplementations where files don't fall under the licensing exemption. This may lead to incompatibilities with upstream and should be kept in mind, some of the discrepancies are:
* No support for endianess in `bit_field.h`
* Only `DECLARE_ENUM_FLAG_OPERATORS` is implemented in `common_funcs.h`
* Only `DEBUG_ASSERT` and `INSERT_PADDING_*` are implemented in `assert.h`
* Only a subset of used settings are implemented in `setttings.h`
* All `LOG_*` macros are handled by proxy in `log.h`
* Any unscoped classes are placed in the `AudioCore` namespace to avoid include conflicts
