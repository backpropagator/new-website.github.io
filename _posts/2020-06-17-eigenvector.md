---
layout: post
title: 'Pondering Upon Eigenvectors'
date: 2020-06-17 11:12:00-0400
description: basics of eigenvectors/eigenvalues
tags: math, basics
categories: math
---

Eigenvectors and eigenvalues are like the VIPs of mathematics—showing up everywhere from machine learning to quantum physics, control theory to signal processing, even sneaking into Markov processes. They’re powerful, they’re essential, but let’s be real: their geometric meaning often feels like a mystery wrapped in an enigma for most learners. So, buckle up! This post is here to unravel eigenvectors and eigenvalues with some intuitive flair and a peek into how they’re computed, while addressing a few tricky spots that might trip you up.

## Matrices as Transformations? Oh Yes!

To get to eigenvectors, we start with matrices. You might see a matrix as just a grid of numbers waiting to be crunched. Fair enough. But here’s a mind-blowing twist: **matrices define linear transformations**—they take vectors and morph them into something new!

Take the simplest example, the identity matrix:

$$
A = \begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix}
$$

Multiply this by any vector $$ \alpha = \left( \begin{array}{c} \alpha_1 \\ \alpha_2 \\ \end{array} \right) $$, and—surprise!—you get \(\alpha\) right back. Boring? Maybe. But stick with me, because this is where the fun begins.

Let’s break down that multiplication. The usual way is:

$$
A\alpha = \begin{pmatrix} 1 & 0 \end{pmatrix} \begin{pmatrix} \alpha_1 \\ \alpha_2 \end{pmatrix} + \begin{pmatrix} 0 & 1 \end{pmatrix} \begin{pmatrix} \alpha_1 \\ \alpha_2 \end{pmatrix} = \begin{pmatrix} 1 \cdot \alpha_1 + 0 \cdot \alpha_2 \\ 0 \cdot \alpha_1 + 1 \cdot \alpha_2 \end{pmatrix}
$$

Yup, that’s the classic row-by-column drill. But here’s a cooler perspective:

$$
A\alpha = \alpha_1 \begin{pmatrix} 1 \\ 0 \end{pmatrix} + \alpha_2 \begin{pmatrix} 0 \\ 1 \end{pmatrix}
$$

Whoa! What’s happening here? The columns of \(A\) — $$ \left(\begin{array}{c} 1 \\ 0 \end{array}\right) $$ and $$ \left(\begin{array}{c} 0 \\ 1 \end{array}\right) $$—are being **scaled** by $$ \alpha_1 $$ and $$ \alpha_2 $$, then added together. Recognize those columns? They’re the standard basis vectors $$\hat{i}$$ and $$\hat{j}$$ in 2D space! So, $$A\alpha = \alpha_1 \hat{i} + \alpha_2 \hat{j}$$, which is just $$\alpha$$. No transformation here, just a round-trip back to itself.

Now, let’s spice things up with a wilder matrix:

$$
A = \begin{pmatrix} x_1 & x_2 \\ y_1 & y_2 \end{pmatrix}
$$

Same deal—multiply it by $$\alpha$$:

$$
A\alpha = \alpha_1 \begin{pmatrix} x_1 \\ y_1 \end{pmatrix} + \alpha_2 \begin{pmatrix} x_2 \\ y_2 \end{pmatrix}
$$

Here, the columns $$\begin{pmatrix} x_1 \\ y_1 \end{pmatrix}$$ and $$\begin{pmatrix} x_2 \\ y_2 \end{pmatrix}$$ are the new “directions” (or basis vectors). The result? A vector built by scaling these columns and summing them up. In vector-speak, that’s $$\alpha_1 (x_1 \hat{i} + y_1 \hat{j}) + \alpha_2 (x_2 \hat{i} + y_2 \hat{j})$$. Neat, right?

So, what’s the transformation? Picture $$\alpha$$ as a point in 2D space, originally lounging in a coordinate system with axes $$\hat{i}$$ and $$\hat{j}$$. Multiply by $$A$$, and bam—it’s now expressed relative to a new set of basis vectors $$\begin{pmatrix} x_1 \\ y_1 \end{pmatrix}$$ and $$\begin{pmatrix} x_2 \\ y_2 \end{pmatrix}$$—assuming those columns are linearly independent. The matrix **defines a linear transformation** that can often be visualized as mapping vectors relative to this new basis. But here’s a heads-up: not every matrix simply “changes the coordinate system”—some squash space into lower dimensions or stretch it in funky ways. We’ll see more of that soon!

## What’s the Deal with These “Eigen” Things?

With matrices twisting space like a sci-fi plot, let’s meet the stars: eigenvectors and eigenvalues.

When a matrix transforms a vector, it usually stretches, squashes, or spins it every which way. But there are **special vectors** that stay chill—they don’t change direction, only their size. These are **eigenvectors**, and the scaling factor? That’s the **eigenvalue**.

In math terms, for a matrix $$A$$ and vector $$x$$, if:

$$
Ax = \lambda x
$$

where $$\lambda$$ is a scalar, then $$x$$ is an eigenvector, and $$\lambda$$ is its eigenvalue. The vector $$x$$ gets stretched or shrunk by $$\lambda$$, but its direction? Untouched.

To hunt these down, we solve:

$$
\det(A - \lambda I) = 0
$$

This gives us the eigenvalues $$\lambda$$. Then, for each $$\lambda$$, we find the eigenvectors by solving $$(A - \lambda I)x = 0$$, which defines the **null space**—all vectors that $$A - \lambda I$$ maps to zero. Those are our eigenvectors!

## Watch Out for These Gems: Span and Rank

Let’s level up with two key ideas: **span** and **rank**.

- **Span**: The set of all possible linear combinations of a matrix’s columns. It’s the “space” they cover.
- **Rank**: The number of linearly independent columns in a matrix. It tells us the dimension of the transformed space.

Check out this matrix:

$$
A = \begin{pmatrix} 1 & 2 & 5 \\ 3 & 5 & 13 \\ 7 & 6 & 19 \end{pmatrix}
$$

Looks like it takes a 3D vector ($$\mathbb{R}^3$$) and spits out another 3D vector, right? Not so fast! Peek at the columns:

- $$\begin{pmatrix} 5 \\ 13 \\ 19 \end{pmatrix} = 1 \cdot \begin{pmatrix} 1 \\ 3 \\ 7 \end{pmatrix} + 2 \cdot \begin{pmatrix} 2 \\ 5 \\ 6 \end{pmatrix}$$

The third column is just a mix of the first two—it’s **dependent**. So, these three vectors are coplanar, spanning only a 2D plane in 3D space. The rank? 2, not 3. When $$A$$ transforms a vector, it **squashes** $$\mathbb{R}^3$$ onto that 2D plane.

What’s this got to do with eigenvectors? Here’s where it gets interesting—and a bit tricky. You might think the number of non-zero eigenvectors equals the rank, but let’s clarify: **for diagonalizable matrices**, the number of linearly independent eigenvectors corresponding to non-zero eigenvalues equals the rank. In this example, with rank 2, we’d expect two such eigenvectors if $$A$$ is diagonalizable, spanning that 2D plane. The third dimension? It’s crushed, linked to an eigenvalue of zero. But caution: not all matrices are diagonalizable (think defective matrices with repeated eigenvalues but fewer eigenvectors)—in those cases, the eigenvector count might not match up so neatly. For now, let’s assume our matrix plays nice and is diagonalizable.

## Why Do They Pop Up Everywhere?

Eigenvectors and eigenvalues are the secret sauce of linear transformations. They let us break down a matrix into stretching or squashing along specific directions—way easier to wrap your head around!

Enter **eigenvalue decomposition**:

$$
A = V \Lambda V^{-1}
$$

Here, $$V$$ is packed with eigenvectors as columns, and $$\Lambda$$ is a diagonal matrix of eigenvalues. This trick simplifies everything—think powers of $$A$$, system dynamics in control theory, or signal modes in processing. It’s a game-changer! (Note: This only works for diagonalizable matrices—another reason that distinction matters.)

## Wrapping It Up

Eigenvectors and eigenvalues turn the abstract world of matrices into something tangible—directions that hold steady under transformation, scaled by neat little numbers. We’ve clarified that matrices define transformations (not just coordinate swaps), and the eigenvector-rank connection holds for diagonalizable cases. Hopefully, this journey has shed some light on their magic—and their quirks!

Want more? Check these out:

1. [3Blue1Brown’s Eigenvectors Video](https://www.youtube.com/watch?v=PFDu9oVAE-g) - Stunning visuals!
2. [Setosa.io’s Interactive Eigen Exploration](https://setosa.io/ev/eigenvectors-and-eigenvalues/) - Play around with it!
3. [Gilbert Strang’s Lecture](https://www.youtube.com/watch?v=DzqE7tj7eIM) - Deep theory from a legend.

Thanks for reading! Got thoughts? Drop some feedback—I’d love to hear it!