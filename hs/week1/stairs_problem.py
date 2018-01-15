'''
  @ file name : stairs_problem.py
  @ brief     : homework
  @ author    :
  @ desc      : A boy is willing to walk up 'n' steps.
                He can go up one, two, three step at a time.
                Develope a function that can calculate all the possible ways for a boy to walk up the stairs.
'''

def walking_up_the_stairs(total_steps, unit_steps):
    answer = unit_steps**total_steps
    value = walk_up_step(total_steps, unit_steps);
    print "answer           : ", answer
    print "calculated value : ", value


    
    
def walk_up_step(total_steps, unit_steps):
    total_steps -= 1;
    if total_steps<0 :
        return 1
    return walk_up_step(total_steps, unit_steps)*unit_steps


unit_step          = 3
total_num_of_steps = 3

walking_up_the_stairs(total_num_of_steps, unit_step)
