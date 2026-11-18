#ifndef TRANSLATE_H
#define TRANSLATE_H

/**
 * @brief Main function that translates vm file(s) to Hack assembly
 * 
 * @param[in] vm_paths      Paths to vm files to translate, an array of char arrays.
 * @param[in] num_vm_paths  Length of vm_paths
 * @param[in] out_path      Path to output file, to be made by this function.
 * @return 0 on success.
 */
int translate(const char** vm_paths, int num_vm_paths, const char* out_path);

#endif
