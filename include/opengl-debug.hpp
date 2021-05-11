#ifndef A90BF5E4_BC77_49EC_A037_FD17B7336109
#define A90BF5E4_BC77_49EC_A037_FD17B7336109

#include <string_view>

namespace OpenGLDebug {
    // Print out all of the errors generated by the previous OpenGL call
    void printErrors(std::string_view file, int line);
    
    // Check the OpenGL call for errors
    template<typename callType, typename... argsType>
    void glCallImpl(std::string_view file, int line, callType call, argsType... args) {
        call(args...);
        printErrors(file, line);
    }
    
    // Same as the function above, but returns a value instead of null
    template<typename callType, typename... argsType>
    auto glCallRImpl(std::string_view file, int line, callType call, argsType... args) {
        auto result = call(args...);
        printErrors(file, line);
        return result;
    }
}

#endif /* A90BF5E4_BC77_49EC_A037_FD17B7336109 */
