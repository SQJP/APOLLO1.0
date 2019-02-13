/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 * @brief Defines the StringTokenizer class
 * StringTokenizer类主要目的是使用特定的分割符将字符串分割成多个部分。作用与python的字符串分割函数split()类似。默认分割符是" " 
 */

#ifndef MODULES_COMMON_UTIL_STRING_TOKENIZER_H_
#define MODULES_COMMON_UTIL_STRING_TOKENIZER_H_

#include <string>
#include <vector>

/**
 * @namespace apollo::common::util
 * @brief apollo::common::util
 */
namespace apollo {
namespace common {
namespace util {

/**
 * @class StringTokenizer
 * @brief Used for splitting strings with respect to given delimiters.
 */
class StringTokenizer {
 public:
  /**
   * @brief Constructor
   * @param s String to be split
   * @param delims Delimiters where the string should be split
   */
  StringTokenizer(const std::string& s, const std::string& delims = " ");

  /**
   * Destructor
   */
  virtual ~StringTokenizer() = default;

  /**
   * @brief Static method; creates a vector with the non-empty tokens obtained
   * from splitting.
   * @param str String to be split
   * @param delims Delimiters where the string should be split
   * @return A vector of tokens, each a substring of str
   * surrounded by delimiters.
   * 使用分隔符delims对给定的字符串str进行分割。分割结果可以用 Next()成员函数访问;
   */
  static std::vector<std::string> Split(const std::string& str,
                                        const std::string& delims);

  /**
   * @brief The i-th time Next() is called, it returns the i-th token obtained
   * from splitting the string fed to the initializer at the given delimiters;
   * once the end is reached, will always return "".
   * @return A token, which is a substring of the string fed to the initializer
   */
  std::string Next();

 private:
  std::string s_;

  std::string delims_;

  size_t index_;

  size_t last_index_;
};

}  // namespace util
}  // namespace common
}  // namespace apollo

#endif /* MODULES_COMMON_UTIL_STRING_TOKENIZER_H_ */
