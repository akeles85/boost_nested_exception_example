In this project, you can find the usage of nested exception with boost::async.

As boost::async holds the exception with boost::exception type, the nested std::exception cannot be used. Boost does not support nested exceptions via std::exception. 
Instead of this, we should use boost mechanism to propagate nested exceptions. 

## std nested exception with boost async (std_exception)

You can see the problem with nested exceptions in this code.

## boost nested exception with boost async

You can see the usage of nested exceptions with Boost in this code.

