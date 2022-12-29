---
layout: post
title: 'Pondering upon Eigenvectors'
date: 2020-06-17 11:12:00-0400
description: basics of eigenvectors/eigenvalues
tags: math, basics
categories: math
---
The Eigenvectors & Eigenvalues pop up in many places of mathematical analysis and application. For example: Machine Learning, Control Theory, Signal Processing, Quantum Physics, Markov Process just to name a few! Despite it's wide applications, it isn't entirely clear as to what do these Eigenvectors represent and what is their significance in all these applications. Also, many students see Eigenvectors as a bunch of steps to find a vector which is going to help them, and hence they have very little intuition about them. In this post, I plan to give an intuition of the same and also provide some insights of how it is calculated algorithmically.

## Matrix as Transformations!

Well to understand this, we need to understand what a **"Matrix"** is? Generally, matrices are seen as a bunch of numbers inside a box used to perform collective operations. It's one way to look at it. But a higher level insight is to look at matrices as a **Transformation**!

Let's take an example, let $$A = \left( \begin{array}{cc} 1 & 0 \\ 0 & 1 \end{array} \right) $$.
If we multiply any vector
$$ \alpha = \left( \begin{array}{c} \alpha_1 \\ \alpha_2 \\ \end{array} \right) $$ with $$A$$, we'll get the same vector. Not interesting right?

But here is where it gets interesting, we can look at this multiplication in 2 ways. One way is

$$A\alpha = \begin{pmatrix} 1 & 0 \end{pmatrix} \begin{pmatrix} \alpha_1 \\\ \alpha_2 \end{pmatrix} + 
\begin{pmatrix} 0 & 1 \end{pmatrix} \begin{pmatrix} \alpha_1 \\\ \alpha_2 \end{pmatrix}$$

or,

$$
A\alpha = \left( \begin{array}{cc} (1*\alpha_1) + (0*\alpha_2) \\ (0*\alpha_1) + (1*\alpha_2) \\ \end{array} \right)
$$

which is the traditional way to multiply 2 matrices. But there's another way to look at it, instead of multiplying rows of by columns, we can multiply columns by rows, here's what I mean -

$$
A\alpha = \left( \begin{array}{c} 1 \\ 0 \\ \end{array} \right)\alpha_1 + \left( \begin{array}{c} 0 \\ 1 \\ \end{array} \right)\alpha_2
$$

from this way of multiplication, we can see that this multiplication is essentially addition of two seperate column vectors, where each column vector is obtained by taking the columns of $$A$$ and **scaling** them by elements of $$\alpha$$! In other words, if we want to find the product of a matrix with a vector, just take the columns of the matrix, scale them by corresponding amount in the vector and sum them up. So, we scale the first column by $$\alpha_1$$ and second column by $$\alpha_2$$ and add them up.

Does this seem familiar? If you were thinking of Vectors, you are right! This is indeed the essence of a Matrix that **the columns of a Matrix represent the vectors which span the range of the Matrix**, these vectors are also called **Basis Vectors**.

Going back to our example, the columns of $$A$$ :
$$
\left( \begin{array}{c} 1 \\ 0 \\ \end{array} \right)
$$ 
&
$$ 
\left( \begin{array}{c} 0 \\ 1 \\ \end{array} \right)
$$
in a way, represent the directions in which we need to travel to get our answer (the product), so you need to go $$\alpha_1$$ amount in the direction of
$$
\left( \begin{array}{c} 1 \\ 0 \\ \end{array} \right)
$$ 
and $$\alpha_2$$ amount in the direction of
$$
\left( \begin{array}{c} 0 \\ 1 \\ \end{array} \right)
$$ 
to get the product $$A\alpha$$.\\
In terms of vectors, one can interpret the columns of matrix as vector directions of $$\hat i$$ & $$\hat j$$ and the multiplication $$A\alpha$$ is nothing but the vector $$ \alpha_1 \hat i + \alpha_2 \hat j $$.

Cool! but what if the matrix isn't trivial like this one? say 
$$A = \left( \begin{array}{cc} x_1 & x_2 \\ y_1 & y_2 \\ \end{array} \right)$$
this makes a very little difference. Instead of the component directions being $$\hat i$$ & $$\hat j$$, the direction of each column will be $$ (x_1 \hat i + y_1 \hat j) $$ & $$ (x_2 \hat i + y_2 \hat j) $$ respectively.
And the product $$ A \alpha $$ is nothing but  $$ \alpha_1 (x_1 \hat i + y_1 \hat j)  + \alpha_2 (x_2 \hat i + y_2 \hat j)$$! This is really a nice way to look at matrix multiplications which relate Matrices to Vectors in such an intuitive way!

Now, where is transformation in all this? For this we need to look at $$\alpha$$. \\
Any $$\alpha$$ with dimension $$(2 \times 1)$$ can represent a point in 2-dimension.  So, $$\alpha \in \mathcal{R}^2$$ and after multiplying by $$A$$, the product $$A\alpha \in \mathcal{R}^2$$ too. So, we can say that $$A$$ maps a vector from $$\mathcal{R}^2$$ to $$\mathcal{R}^2$$, **but is it the same Coordinate System?** The answer is **No!** the coordinate system has changed indeed but how? Think of it this way - originally, $$\alpha$$ was in original $$2D$$ plane whose axis were 
$$
\left( \begin{array}{c} 1 \\ 0 \\ \end{array} \right)
$$ 
&
$$
\left( \begin{array}{c} 0 \\ 1 \\ \end{array} \right)
$$ 
(or $$\hat i$$ & $$\hat j$$), so to go to any point we need to go some distance along $$\hat i$$ and some distance along $$\hat j$$, but after multiplying it by $$A$$, the axis are changed to 
$$
\left( \begin{array}{c} x_1 \\ y_1 \\ \end{array} \right)
$$ 
&
$$
\left( \begin{array}{c} x_2 \\ y_2 \\ \end{array} \right)
$$ 
(or $$(x_1 \hat i + y_1 \hat j)$$ & $$(x_2 \hat i + y_2 \hat j)$$). So, can you see the transformation? The axis of the coordinate system is changed after multiplying with a matrix. More clearly-

$$
\left( \begin{array}{c} 1 \\ 0 \\ \end{array} \right) \rightarrow \left( \begin{array}{c} x_1 \\ y_1 \\ \end{array} \right)
$$
&nbsp;&nbsp; & &nbsp;&nbsp;
$$
\left( \begin{array}{c} 0 \\ 1 \\ \end{array} \right) \rightarrow \left( \begin{array}{c} x_2 \\ y_2 \\ \end{array} \right)
$$ \\
In literature this axis is also called **Basis Vector**. Basis of a Matrix is a set of vector through which we can get any point (in that dimension) by taking some linear combination of these vectors. There's more to this, but I leave it to the reader to explore for themselves.

## What are these "Eigen" things?

Having an intuition of how matrix can be seen as a Transformation, we are in a position to understand the Eigenvectors & Eigenvalues.

So, while transforming a point from one basis to another by multiplication of a matrix, we map a point original 2D plane to some other point in the transformed plane. If we look at the vectors representing these points, they are also being transformed from one coordinate system to another. However, **there are some vectors that don't change their direction, instead they only get scaled up or scaled down!** These vectors are nothing but the Eigenvectors! and the amount by which they get scaled up or down is the corresponding Eigenvalue!

Mathematically, these are the vectors that after multiplying by $$A$$ get scaled up or down but the direction remains the same. For equation form we need, $$Ax$$ which is in the same direction as $$x$$ but scaled up or down (let's say by $$\lambda$$). So,

$$
Ax = \lambda x
$$

Which is the equation we have been taught since childhood to calculate the eigenvectors & eigenvalues. From this equation, we can find the Eigenvalues of A by solving 

$$
|A - \lambda\mathbb{I}| = 0
$$

, to find the eigenvectors, we will have to find the Basis of Null-Space of
$$
A - \lambda\mathbb{I}
$$
. Null Space of a matrix $$A$$ (also written as $$N(A)$$) contains all the vectors $$x$$ such that, $$Ax=0$$, so finding basis of 
$$ N(A-\lambda\mathbb{I}) $$ 
means that we have to find basis of all the vectors for which $$ (A - \lambda\mathbb{I})x = 0 $$ which is the definition of Eigenvectors.

## Some things to look for

Okay! so upto this point we have understood what is the physical significance of Eigenvectors. Now there are somethings, we should be aware of. Let's first define some terms.

**Span**: The **span** of a set of vectors is the set of all Linear Combinations of the vectors. Implicitly, Span indicates the dimension that can be covered by using a set of vectors.

**Rank**: Rank of a matrix is defined as the maximum number of linearly independent columns in a matrix. This is the textbook defiition of Rank. It's physical significance is that, Rank of a matrix denotes the dimension of the transformed coordinate system. To understand this, let's take an example 
$$A = \left( \begin{array}{ccc} 1 & 2 & 5 \\ 3 & 5 & 13 \\ 7 & 6 & 19 \\ \end{array} \right)$$

So, if a vector of dimension $$(3 \times 1)$$ is multiplied by A, we'll get a $$(3 \times 1)$$ vector. Seems nice! It looks like $$A$$ produces a vector in 3D. But, it's not the case! if we look carefully, then we can see that, there are only 2 independent column in $$A$$!

$$
C_3 = C_1 + 2C_2
$$ 

where $$C_1, C_2$$ & $$C_3$$ are the columns of $$A$$ \\
So, what this means is, these 3 columns/vectors are **Coplanar**, so taking any linear combination of these vectors would give us a point in this plane itself! So, the Span of the matrix is $$\mathcal{R}^2$$ and not $$\mathcal{R}^3$$! We can also see this by a simple calculation, take any linear combination of columns of $$A$$-

$$
C = \alpha_1 C_1 + \alpha_2 C_2 + \alpha_3 C_3
$$

Using $$(5)$$

$$
C = \alpha_1 C_1 + \alpha_2 C_2 + \alpha3 (C_1 + 2C_2) \\
= (\alpha_1 + \alpha_3) C_1 + (\alpha_2 + 2 \alpha_3) C_2 \\
C = \beta_1 C_1 + \beta_2 C_2
$$

So, though it looks like $$A$$ maps a vector to $$\mathcal{R}^3$$ but, it actually maps it to $$\mathcal{R}^2$$. Hence, rank of the matrix is 2! 

That being said, let's try to visualize the transformation this matrix is performing. So, we know that the input space is $$\mathcal{R}^3$$ and the output space is $$\mathcal{R}^2$$, this means that, the transformation in some way, squashes the entire 3D system into 2D system!\\
So, what does it have to do with eigenvectors & eigenvalues?  Well the number of non-zero Eigenvectors will be equal to Rank of the matrix. This is quite intuitive, because a 2D plane can only have a maximum of 2 Eigenvectors (any 3rd vector can be represented as sum of these 2), and the 3rd Eigenvector would come from the sqashing of the 3D space for which the Eigenvalue will be 0! \\
So, thing to take away is the number of non-zero Eigenvectors will be equal to the Rank of the Matrix.

**Note**: This discussion is valid for any $$n$$-dimensional matrix.

## So why do they pop up everywhere?

Well simply put, Eigenvectors make understanding/visualizing Linear transforms easier! We can analyse any Linear transform as stretching or compressing of a vector. Which makes things much easier, we can always decompose a matrix in terms of it's eigenvectors & eigenvalues.

$$
A = V^{-1} \Lambda V
$$

where $$V$$ is the matrix containing Eigenvectors & $$\Lambda$$ is a Diagonal matrix with Eigenvalues as the diagonal values. This Factorisation is also called **Eigenvalue decomposition**, which is heavily used in Control Theory & Signal Processing.

Well that's it! Hope I have explained the concepts clearly. Any feedback will be highly valued.

## Footnotes

1. [3Blue 1Brown's video on Eigenvectors & Eigenvalues](https://www.youtube.com/watch?v=PFDu9oVAE-g) is a really nice video! The animations were really helpful for me while understanding these concepts.

2. [Setosa.io's blog on Eigenvectors & Eigenvalues](https://setosa.io/ev/eigenvectors-and-eigenvalues/) are also nice tool to visualize the same.

3. [Gilbert Strang's lecture on Eigenvectors & Eigenvalues](https://www.youtube.com/watch?v=DzqE7tj7eIM) give a very theorotical insight into Eigenvectors.
