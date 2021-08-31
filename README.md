# HW02 - Slay the Lernaean Hydra

Driven mad by CSC131, the Student smashed their laptop.

After recovering their sanity, the Student deeply regretted their actions; they were purified by Chair of the CS Department, then traveled to Cheek 209 to inquire how they could atone for their actions. The Executive Assistant and Oracle of Delphi, advised them to go to Cheek 61M and serve its occupant, Jim Daehn, for one semester, performing whatever labors Jim might set upon them; in return, they would be rewarded with immortality, or at least forward movement in their curriculum.

The Student despaired at this, loathing to serve a man whom they knew to be far inferior to themselves, yet fearing to oppose the Chair. Eventually, they placed themselves at Jim's disposal.

Jim originally ordered the Student to perform ten labors. The Student accomplished these tasks, but Jim refused to recognize two: the slaying of the [Lernaean Hydra](https://en.wikipedia.org/wiki/Labours_of_Hercules#Second:_Lernaean_Hydra), as the Students' GA had helped them; and the cleansing of the [Augeas](https://en.wikipedia.org/wiki/Labours_of_Hercules#Fifth:_Augean_stables), because the Student accepted payment for the labor.

Jim set two more tasks (fetching the [Golden Apples of Hesperides](https://en.wikipedia.org/wiki/Labours_of_Hercules#Eleventh:_Golden_Apples_of_the_Hesperides) and capturing [Cerberus](https://en.wikipedia.org/wiki/Labours_of_Hercules#Twelfth:_Cerberus)), which the Student also performed, bringing the total number of tasks to twelve.

Having slain the Nemean Lion, the Student is now prepared to [Slay the Lernaean Hydra](https://en.wikipedia.org/wiki/Labours_of_Hercules#Second:_Lernaean_Hydra)...

<p><a href="https://commons.wikimedia.org/wiki/File:Gustave_Moreau_003.jpg#/media/File:Gustave_Moreau_003.jpg"><img src="https://upload.wikimedia.org/wikipedia/commons/6/61/Gustave_Moreau_003.jpg" alt="Gustave Moreau 003.jpg" height="480" width="410"></a></p>

## Recursion: Ackermann's Function

_Note: This assignment is related to the Exercise 26 of Chapter 2 found in **Data Abstraction and Problem-Solving with C++**, seventh edition, by Carrano & Henry. See [our disclaimer below](#disclaimer--fair-use-statement)._

This assignment is primarily meant to give the student experience in writing a recursive function. This effort, of course, entails a thorough examination of the four fundamentals questions for constructing recursive solutions:

1. How can you define the problem in terms of a smaller problem of the same type?
2. How does each recursive call diminish the size of the problem?
3. What instance of the problem can serve as the base case?
4. As the problem size diminishes, will you reach this base case?

## Objectives

In this assignment you

* implement a solution to Ackermann's Function
* modify an existing file under revision control
* continue to learn basic git commands for staging changes, committing changes and pushing them to GitHub
* continue to learn how to assemble a pull request for review by your instructor and graduate assistants

Upon successful completion of this assignment, the student will implement the following problem:

> Consider the following recursive definition:
```
              { n + 1, if m = 0
Acker(m, n) = { Acker(m - 1, 1) if n = 0
              { Acker(m - 1, Acker(m, n - 1)) otherwise
```

This function, called _Ackermann's function_, is of interest because it grows rapidly with respect to the sizes of _m_ and _n_. To get a sense of how this function operates, try computing the following by hand first: `Acker(1, 2)`.

Caution: Even for modest values of _m_ and _n_, Ackermann's function requires _many_ recursive calls.

## Background Reading

Before you tackle this assignment, it is advised that you read and understand the following in Carrano & Henry:

* **Appendix A** Review of C++ Fundamentals
* **Appendix B** Important Themes in Programming
* **Chapter 2** Recursion: The Mirrors

If you have not read these chapters, do it now!

## C++ Concepts Overview

This assignment simply covers the concept of a recursive function. As mentioned above in the introduction of this assignment, a well designed recursive function is constructed by determing the answers to four basic questions. Before you code your solution, take the time to answer these questions.

### Namespaces

The Ackermann function is to be implemented as part of the `csc232` namespace. Making a function definition a part of a namespace is as simple as implementing said function _within_ the given namespace. You'll find a `TODO` statement in [include/csc232.h](include/csc232.h) that explicitly has you writing your function definition within the proper namespace. **It is imperative that your function is defined within this namespace! The Catch2 unit tests rely on this organization**.

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/a/3IULbojN), clone this repository. Once cloned, create a new branch named `develop` within which to do your work. Ultimately, you will create a pull request that seeks to merge your `develop` branch into your `trunk` branch.

To create your new branch and push it to GitHub, issue the following `git` commands:

```bash
git checkout -b develop
git push -u origin develop
```

**NOTE**: The `-b` switch on the original `checkout` and the `-u origin develop` is required only the _first_ time you push your branch to GitHub. All subsequent pushes are done by merely typing

```bash
git push
```

Once your branch has been pushed to GitHub and you have pushed some changes that you have committed on your branch, you are ready to create a pull request. When creating this pull request, be sure to request that you seek to merge changes in your `develop` branch _into_ your `trunk` branch.

You can create this pull request anytime after you've pushed a commit to your `develop` branch. If you find that you have additional commits to push to GitHub, there is no need to create another pull request; the existing one is automatically with your latest pushes.

If you're using Microsoft Visual Code, you can open your source repository from with GitBash using the command:

```bash
code .
```

Don't forget the trailing period `.` for it specifies to code that you want to open the current directory.

## Tasks

This assignment requires three basic tasks:

1. Modify `csc232.h` so that it implements the `acker()` function. See the `TODO` statement indicating _where_ within this file your function definition should be written.
2. Document the `acker()` function accordingly
3. Delete the line containing the `TODO` statement.

Before you begin, be sure you have thoroughly read through, and understand Chapter 2 and the concept of recursion.

Additional preliminary steps you may want to take:

1. Take a look around this repository.
   1. Note how the code is organized. Notice that all header files are located in an [include](include) folder and all the implementation files are located in the [src](src) folder.
   2. **Unit tests** are located in yet another folder named [test](test). Please note: Unless told otherwise, **never** modify the contents of this folder. These unit tests are executed to determine the degree to which you have successfully completed your assignment.
2. Study the [CMakeLists.txt](CMakeLists.txt) file. What do you suppose is the purpose of this file? _Don't worry too much if you don't understand this file; we will discuss it and how its used by a program named `cmake`.
3. Jot down anything that you don't understand.

### Part 1: Implement the Ackermann Function

In Part 1 of this assignment you will implement the `Acker` function.

1. In the [include](include) folder, modify the file named `csc232.h`.
2. When implementing your function, make sure of the following:
   1. You are writing your code within the indicated `csc232` namespace
   2. You name the function `acker` (note that each letter in the name is lowercase)
   3. The parameter list contains exactly two parameters of type `int`
   4. The return value of the `acker` function is of type `int`
3. When documenting your function, be sure it includes the following tags (with appropriate values):
   1. `@brief`
   2. `@param`
   3. `@pre`
   4. `@post`
   5. `@return`

#### Implementation Notes

Be sure to thoroughly comment your code. Use the `javadoc`-style Doxygen comments to provide a brief description of the function, its parameters, return values and pre and post conditions.

After you have modoified this file, add it to revision control, commit your changes and push the commit to GitHub using the following `git` commands (the output, where it occurred, has been ommitted for clarity).

```bash
git add include/csc232.h
git commit -m"HW02 - Initial import of Ackermann function."
git push
```

As a final step, log onto GitHub and make sure that your pull request has all your commits. If it doesn't, make a final commit and/or push your last commit to GitHub. Also, make sure that `professordaehn`, `lakshmidivyavaddineni` and `SunandaGuha` are listed as a Reviewers on your pull request. (It may be that only `professordaehn` is listed; if that is the case, manually add the GA usernames too. While you're at it, assign the pull request to yourself.)

## Submission Details

As usual, prior to submitting your assignment to Blackboard, be sure that you have committed and pushed your final changes to GitHub. If you have not done so already, create a **pull request** that seeks to merge your `develop` branch into your `trunk` branch.  Submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull request) as a Text Submission in Blackboard. Please note: the timestamp of the submission on Blackboard is used to assess any late penalties if and when warranted.

Finally, be sure that you **do not merge your pull request until it has been approved by one of the assigned reviewers**.

### Due Date

Your Blackboard submission is due by 23:59 Saturday, 04 September 2021.

### Grading Rubric

This assignment is worth **5 points**.

Criteria          | Exceeds Expectations         | Meets Expectations                  | Below Expectations                  | Failure                                                 |
------------------|------------------------------|-------------------------------------|-------------------------------------|---------------------------------------------------------|
Pull Request (20%)| Submitted early, correct url | Submitted on-time; correct url      | Incorrect URL                       | No pull request was created or submitted                |
Code Style (20%)  | Exemplary code style         | Consistent, modern coding style     | Inconsistent coding style           | No style whatsoever or no code changes present          |
Correctness^ (60%)| All unit tests pass          | At least 80% of the unit tests pass | At least 60% of the unit tests pass | Less than 50% of the unit tests pass                    |

^ _The Catch2 Test unit runner, if appropriate, will calculate the correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24 hour period following the due date, this lab will be penalized 1 point meaning the grading starts at 4 (out of 5 total possible) points.
* In the second 24 hour period following the due date, this lab will be penalized 2 points meaning the grading starts at 3 (out of 5 total possible) points.
* After 48 hours, the assignment will not be graded and thus earns no points, i.e., 0 out of 5 possible points.

## Disclaimer & Fair Use Statement

This repository may contain copyrighted material, the use of which may not have been specifically authorized by the copyright owner. This material is available in an effort to explain issues relevant to the course or to illustrate the use and benefits of an educational tool. The material contained in this repository is distributed without profit for research and educational purposes. Only small portions of the original work are being used and those could not be used to easily duplicate the original work.

This constitute a 'fair use' of any such copyrighted material (referenced and provided for in section 107 of the US Copyright Law).

If you wish to use any copyrighted material from this repository for purposes that go beyond 'fair use', you must obtain expressed permission from the copyright owner.
