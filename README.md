# social_network_graph_theory
For this assignment, you will learn about graph theory by creating a program
that will add users to a social network, which will be linked by friends and
followers.
## The rules are this:
1. In Facebook, each time you add a friend, it works both ways. (If A adds B
as a friend, then B is a friend of A as well.) This is called an undirected
graph.
2. In Twitter, if you enter that A has gained B as a follower, then A is not a
follower of B. Though you can add them separately that way as well. This is
called a directed graph.

When the program launches, the user will choose if it is in Facebook or
Twitter mode. This will be fixed for the rest of the program run.

### You will have to implement 5 operations to get an A:
1. You will need to be able to add new users. Users are just single word
usernames, like "Bob" or "Bill" or "Cindy".

2. You will need to be able to have users become friends (Facebook mode) or
followers (Twitter mode) to each other. Facebook mode: If you say that "Bill" becomes
friends with "Bob", then Bob will also become friends with Bill. Twitter mode: If you
say "Bill" gains "Bob" as a follower, then Bill does not follow Bob as well
unless explicitly added as such later.

3. You will need to be able to print out all the friends of one person. This
isn't an entire social network, just all the immediate friends of the user
specified. They must be printed in alphabetical order.

4. You will need to be able to print out the entire social network of a
person (including that person).
This means that if Bill is friends with Bob, and Bob is friends with Cindy,
but Danica is friends with none of them, choosing to print out the network of Bill
### will output:
- Bill
- Bob
- Cindy

5. You will need to be able to print out everyone in
the system. Given the example in #4 above.
### will output:
- Bill
- Bob
- Cindy
- Danica