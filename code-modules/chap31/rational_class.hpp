#ifndef RATIONAL_CLASS_HPP_
#define RATIONAL_CLASS_HPP_

#include <cassert>
#include <iostream>
#include <numeric>

/// Represents a rational number.
struct rational
{  /// Constructs a rational object, given a numerator and a denominator.
  /// Always reduces to normal form.
  /// @param num numerator
  /// @param den denominator
  /// @pre denominator > 0
  rational(int num, int den)
  : numerator{num}, denominator{den}
  {
    reduce();
  }

  rational(int num) : numerator{num}, denominator{1} {}

  /// Assigns a numerator and a denominator, then reduces to normal form.
  /// @param num numerator
  /// @param den denominator
  /// @pre denominator > 0
  void assign(int num, int den)
  {
    numerator = num;
    denominator = den;
    reduce();
  }

  /// Reduces the numerator and denominator by their GCD.
  void reduce()
  {
    assert(denominator != 0);
    if (denominator < 0)
    {
      denominator = -denominator;
      numerator = -numerator;
    }
    int div{std::gcd(numerator, denominator)};
    numerator = numerator / div;
    denominator = denominator / div;
  }

  int numerator;     ///< numerator gets the sign of the rational value
  int denominator;   ///< denominator is always positive

};

#endif
