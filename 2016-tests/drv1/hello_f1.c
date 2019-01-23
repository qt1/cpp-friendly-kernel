#ifdef __cplusplus
extern "C" {
#endif

#include <linux/module.h> /* Needed by all modules */
#include <linux/kernel.h> /* Needed for KERN_INFO */

#ifdef __cplusplus

class Messager
{
public:
    static char * get_message() {
        return "this is c++ !";
    }
};

extern "C" char *get_msg() {
    return Messager::get_message();
}

char msg[] = "hello from f1 - g++  !";

#else //__cplusplus


char *get_msg(void) {
    return "hello from f1 - c ";
}

#endif //__cplusplus

char* f1(void)
{
    return get_msg();
}

#ifdef __cplusplus
}
#endif
