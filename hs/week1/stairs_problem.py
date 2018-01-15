'''
  @ file name : stairs_problem.py
  @ brief     : homework
  @ author    :
  @ desc      : A boy is willing to walk up 'n' steps.
                He can go up one, two, three step at a time.
                Develope a function that can calculate all the possible ways for a boy to walk up the stairs.
'''

def walking_up_the_stairs(total_steps):
    value = walk_up_step(total_steps, 0);
    print "  # of ways : ", value

def walk_up_step(n, unit_steps):
    n -= unit_steps;
    if   n == 0 :
        return 1
    elif n <  0 :
        return 0 
    return walk_up_step(n, 1)+walk_up_step(n, 2)+walk_up_step(n, 3)


walking_up_the_stairs(4)
