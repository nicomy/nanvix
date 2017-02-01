
Skip to content
This repository

    Pull requests
    Issues
    Gist

    @nicomy

1
0

    17

nicomy/nanvix forked from ppenna/nanvix
Code
Pull requests 0
Projects 0
Pulse
Graphs
Settings

sched avec priority

    random 

1 parent 4182832 commit a515e878f83fe6603362feb9700681c1ceaa0409 @nicomy nicomy committed 7 days ago
Showing
with 18 additions and 1 deletion.
19 src/kernel/pm/sched.c
@@ -59,13 +59,26 @@ PUBLIC void resume(struct process *proc)
 		sched(proc);
 }
 
+// /**
+//  * @brief compute counter priority based.
+//  */
+// PUBLIC int prio(struct process *p ){
+// 	return (p->counter * ((-p->priority+100)/10 ) + ((-p->nice+20)/10) );
+// }
+
+PUBLIC int prio(struct process *p ){
+	return (p->counter * (((-p->priority-p->nice)+100)/10 ) );
+}
+
+
 /**
  * @brief Yields the processor.
  */
 PUBLIC void yield(void)
 {
 	struct process *p;    /* Working process.     */
 	struct process *next; /* Next process to run. */
+	
 
 	/* Re-schedule process for execution. */
 	if (curr_proc->state == PROC_RUNNING)
@@ -98,7 +111,8 @@ PUBLIC void yield(void)
 		 * Process with higher
 		 * waiting time found.
 		 */
-		if (p->counter > next->counter)
+		// if (p->counter > next->counter)
+		if(prio(p)>prio(next))
 		{
 			next->counter++;
 			next = p;
@@ -111,6 +125,9 @@ PUBLIC void yield(void)
 		else
 			p->counter++;
 	}
+
+
+
 	
 	/* Switch to next process. */
 	next->priority = PRIO_USER;
0 comments on commit a515e87
@nicomy

Attach files by dragging & dropping,

, or pasting from the clipboard.
Styling with Markdown is supported

You’re receiving notifications because you’re subscribed to this repository.

    Contact GitHub API Training Shop Blog About 

    © 2017 GitHub, Inc. Terms Privacy Security Status Help 

