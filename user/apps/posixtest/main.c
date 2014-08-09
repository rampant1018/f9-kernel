#include <user_runtime.h>
#include <platform/link.h>
#include <l4/utcb.h>
#include <l4io.h>

/* posix layer */
#include <libposix/pthread.h>

#define STACK_SIZE 256

__USER_TEXT void *child_thread(void *args)
{
	printf("child task start\n");

	while(1);

	return 0;
}

static __USER_TEXT void main(user_struct *user)
{
	printf("\nPosix Layer test starts\n");
	pthread_create(NULL, NULL, child_thread, NULL);
	pthread_create(NULL, NULL, child_thread, NULL);

	while(1);

	return;
}

DECLARE_USER(
	255,
	posixtest,
	main,
	DECLARE_FPAGE(0x0, 4 * (UTCB_SIZE + STACK_SIZE))
);