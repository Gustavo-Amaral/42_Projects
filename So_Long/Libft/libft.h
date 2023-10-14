/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:17:45 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/14 20:00:56 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

/**
 * @brief  Converts a char to an integer
 * @note
 * @param  nptr: "Value" to be converted
 * @retval Converted value
 */
int		ft_atoi(const char *nptr);

/**
 * @brief  Sets all indicated memory slots to 0
 * @note
 * @param  s: Starting memory address
 * @param  n: Number of memory slots to be set, starting from address s
 * @retval None
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief  Allocates (nmemb * size) bytes in memory and initializes it to 0
 * @note
 * @param  nmemb: Size of variable
 * @param  size: Number of variables of size nmemb
 * @retval None
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief  Checks if the character is alfanumeric
 * @note
 * @param  c: Character to be checked
 * @retval 1 if true, 0 if false
 */
int		ft_isalnum(int c);

/**
 * @brief  Checks if the character is alphabetic
 * @note
 * @param  c: Character to be checked
 * @retval 1 if true, 0 if false
 */
int		ft_isalpha(int c);

/**
 * @brief  Checks if the character is ascii
 * @note
 * @param  c: Character to be checked
 * @retval 1 if true, 0 if false
 */
int		ft_isascii(int c);

/**
 * @brief  Checks if the character is numeric
 * @note
 * @param  c: Character to be checked
 * @retval 1 if true, 0 if false
 */
int		ft_isdigit(int c);

/**
 * @brief  Checks if the character is printable
 * @note
 * @param  c: Character to be checked
 * @retval 1 if true, 0 if false
 */
int		ft_isprint(int c);

/**
 * @brief  Converts an integer to a character, unit by unit
 * @note   Memory needs to be freed, 
 * since it is allocated for the returned string
 * @param  n: integer to be converted
 * @retval Converted resultant characters
 */
char	*ft_itoa(int n);

/**
 * @brief  Searches for a value into a memory array
 * @note
 * @param  s: Starting memory pointer
 * @param  c: Value to be searched for
 * @param  n: How many slots in memory to search
 * @retval Pointer to the slot where the value was found, 
 * if not found, return NULL
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief  Compares two memory arrays, 
 * from starting point to offset n
 * @note
 * @param  s1: Pointer to first memory array to be compared
 * @param  s2: Pointer to second memory array to be compared
 * @param  n: Size to offset s1 and s2 for comparison
 * @retval Returns a positive value if s1 > s2, 
 * negative value if s1 < s2 and 0 if s1 = s2
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief  Copies src content to dest, up to n bytes
 * @note  MEMORY MAY NOT OVERLAP
 * @param  dest: Destination pointer
 * @param  src: Source pointer
 * @param  n: Ammount of bytes to be copied from src to dest
 * @retval Pointer to dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief  Copies src content to dest, up to n bytes
 * @note   MEMORY MAY OVERLAP
 * @param  dest: Destination pointer
 * @param  src: Source pointer
 * @param  n: Ammount of bytes to be copied from src to dest
 * @retval Pointer to dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief  Sets up to n bytes of memory pointed by pointer s to value of c
 * @note
 * @param  s: Pointer to the memory area that is going to be set
 * @param  c: Value that is going to set
 * @param  n: Ammount of bytes to be set
 * @retval Pointer to memory area s
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief  Prints a character on the selected file descriptor
 * @note
 * @param  c: Character to be print
 * @param  fd: File descriptor
 * @retval None
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief  Prints a character on the standard output
 * @note
 * @param  c: Character to be print
 * @retval None
 */
void	ft_putchar(char c);

/**
 * @brief  Prints a string and a newline ("\n") on the selected file descriptor
 * @note
 * @param  *s: String to be print
 * @param  fd: File descriptor
 * @retval None
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief  Prints a number on the selected file descriptor
 * @note
 * @param  n: Number to be print
 * @param  fd: File descriptor
 * @retval None
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief  Prints a number on the standard output
 * @note
 * @param  nb: Number to be print
 * @retval None
 */
void	ft_putnbr(int nb);

/**
 * @brief  Prints a string on the selected file descriptor
 * @note
 * @param  s: String to be print
 * @param  fd: File descriptor
 * @retval None
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief  Prints a string on the standard output
 * @note
 * @param  str: String to be print
 * @retval None
 */
void	ft_putstr(char *str);

/**
 * @brief  Splits a string into smaller strings 
 * that are separated by character 'c'
 * @note   Each word contains, as the last characters, 
 * the delimiter 'c' followed by '\0'
 * @param  s: String to be split
 * @param  c: Delimiting character
 * @retval Returns a pointer to a pointer to the first separated string
 */
char	**ft_split(char const *s, char c);

/**
 * @brief  Searches for the first occurrency of character c in the string s
 * @note
 * @param  s: String to be searched
 * @param  c: Character to be searched in the string
 * @retval Returns a pointer to occurrency of c, NULL if c is not found
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief  Compares two strings
 * @note
 * @param  s1: First string to be compared
 * @param  s2: Second string to be compared
 * @retval Returns a positive value if s1 > s2, 
 * negative value if s1 < s2 and NULL if s1 = s2
 */
int		ft_strcmp(char *s1, char *s2);

/**
 * @brief  Duplicates a string into another allocated memory block
 * @note   Pointer needs to be freed after its use,
 * since memory is allocated inside function
 * @param  s: String to be duplicated
 * @retval Returns a pointer to the duplicated string
 */
char	*ft_strdup(const char *s);

/**
 * @brief  Iterates over a string, 
 * using the function pointed by f on each element of the string
 * @note   
 * @param  s: String to be iterated on
 * @param  f: Pointer to a function that is going to iterate each element
 * @retval None
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief  Allocates memory and join two strings into one
 * @note   Pointer needs to be freed after its use,
 * since memory is allocated inside function
 * @param  s1: First string to be joined
 * @param  s2: Second string, is going to be appended 
 * to the end of the first string
 * @retval Returns a pointer to the newly joined string
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief  Concatenates string pointed by src into dst 
 * pointed string, up to size bytes
 * @note  Size must include one byte for NUL-terminating character
 * @param  dst: Destination string
 * @param  src: Source string to be concatenated on dst
 * @param  size: Ammount of bytes to be concatenated (dst + desired ammount + 1)
 * @retval Returns the total length of the newly concatenated string
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief  copies up to size - 1 characters 
 * from the NUL-terminated string src to dst, 
 * NUL-terminating the result
 * @note  Size must include one byte for NUL-terminating character
 * @param  dst: Destination pointer
 * @param  src: Pointer to the string to be copied
 * @param  size: Ammount of bytes to be copied
 * @retval Returns the total length of the newly copied string
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief  Measures the length of a string
 * @note
 * @param  s: String to be measured
 * @retval Returns the total length of the string s
 */
size_t	ft_strlen(const char *s);

/**
 * @brief  Allocates memory to a newly created string, 
 * that is created over the iteration, 
 * of the function pointed to by f, over the string s
 * @note
 * @param  s: String to be iterated on f
 * @param  f: Pointer to function that is going to iterate s
 * @retval Returns the newly created string, 
 * resulting of the iteration of f over s
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief  compares only the first (at most) n bytes of 
 * strings s1 and s2
 * @note
 * @param  s1: Pointer to first string to be compared
 * @param  s2: Pointer to second string to be compared
 * @param  n: Ammount of bytes to be compared
 * @retval Returns a positive value if s1 > s2, 
 * negative value if s1 < s2 and NULL if s1 = s2
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief  finds the first occurrence of the substring little 
 * in the string big, 
 * where not more than len characters are searched
 * @note   The terminating null bytes ('\0') are  not compared
 * @param  big: String to be searched on
 * @param  little: String to be searched for, in big
 * @param  len: Ammount of characters to search for, at most
 * @retval Returns big if little is an empty string; 
 * if little occurs nowherein big, NULL is returned; 
 * otherwise a pointer to the first character 
 * of the first occurrence of little is returned
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief  Searches for the last ocurrence of c in the string s
 * @note
 * @param  s: String to be searched on
 * @param  c: Character to be searched for
 * @retval Returns a pointer to the last occurrence 
 * of the character c in the string s
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief
 * @note
 * @param  s1:
 * @param  set:
 * @retval
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief  Allocates (with malloc(3)) and returns a substring 
 * from the string ’s’.
 * The substring begins at index ’start’ 
 * and is of maximum size ’len’
 * @note
 * @param  s: String from which is the substring 
 * is going to be get
 * @param  start: Starting index from string 's'
 * @param  len: Maximum size for the returned substring
 * @retval Returns a pointer to the formed substring
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief  Swaps the values pointed by a and b
 * @note
 * @param  a: Pointer to a
 * @param  b: Pointer to b
 * @retval None
 */
void	ft_swap(int *a, int *b);

/**
 * @brief  Converts the value of c to lowercase
 * @note
 * @param  c: Value to be converted
 * @retval Returns the converted value of c
 */
int		ft_tolower(int c);

/**
 * @brief  Converts the value of c to uppercase
 * @note
 * @param  c: Value to be converted
 * @retval Returns the converted value of c
 */
int		ft_toupper(int c);

/**
 * @brief  Struct for linked list
 * @note   Content is a pointer for content of the node 
 * and next is a pointer to the next node of the list
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief  Creates a new node with content in it
 * @note
 * @param  content: Pointer to the content of the node
 * @retval Returns a pointer to the newly created node
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief  Adds a new node to the beggining of the linked list
 * @note
 * @param  lst: Pointer to the pointer of the first node of the list
 * @param  new: Pointer to the new node to be placed
 * @retval None
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief  Counts the ammount of nodes in the linked list, 
 * starting from the node lst
 * @note
 * @param  lst: First node to start counting how many nodes in the list, 
 * node pointed by lst included
 * @retval Returns the ammount of nodes in the list, 
 * including node pointed by lst
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief  Points to the last node of the linked list
 * @note
 * @param  lst: Pointer to the node that is going to point to the last node
 * @retval Returns a pointer to the last node of the linked list
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief  Places a new node at the end of the linked list
 * @note
 * @param  lst: Pointer to the linked list
 * @param  new: Pointer to the new node to be placed 
 * at the end of the linked list
 * @retval None
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief  Deletes a node from the linked list
 * @note
 * @param  lst: Pointer to the node to be deleted
 * @param  del: Function in charge to delete the content of the node
 * @retval None
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief  Deletes the whole linked list
 * @note
 * @param  lst: Pointer to the linked list
 * @param  del: Function in charge to delete the content of the node
 * @retval None
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief  Iterates on the nodes, starting from lst, using function, 
 * pointed by f, over the content of the nodes
 * @note
 * @param  lst: Pointer to the first node to be iterated over
 * @param  f: Function in charge of iterating over nodes' contents
 * @retval None
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief  Iterates the list ’lst’ 
 * and applies the function ’f’ on the content of each node. 
 * Creates a new list resulting of the successive applications 
 * of the function ’f’. 
 * The ’del’ function is used to delete the content of a node if needed.
 * @param  lst: Pointer to the first node to be iterated over
 * @param  f: Function in charge of iterating over nodes' 
 * contents
 * @param  del: Function in charge of deleting the nodes, 
 * in case something goes wrong
 * @retval Returns a pointer to the linked list 
 * (Pointer to pointer to the first node)
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));







/************** EXTRA FUNCTIONS **************/

void	decimal_to_hexadecimal(int decimal_number, char *hexadecimal_string);

/**
 * @brief  Reverse a string
 * @note
 * @param  str: String to be reversed
 * @retval None
 */
void	ft_revstr(char *str);

/**
 * @brief  Returns a copy of a 2D array
 * @note   Return is made in void** form, 
 * needs to be casted to wished data type
 * @note   Memory is allocated to the 2D array
 * but also to each 1D array inside of it. 
 * Needs to be freed!
 * @param  array: 2D array to be copied
 * @retval Returns a copy from array
*/
void	**ft_2D_arrcpy(void **array);







/* ****************** GET_NEXT_LINE ****************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FILE
#  define MAX_FILE 10
# endif

/**
 * @brief  Returns the next line from a file descriptor 'fd'
 * @note   Next line is identified by a newline character,
 * or by the end of file.
 * @note   Pointer needs to be freed after its use,
 * since memory is allocated inside function
 * @param  fd: File descriptor pointing to the file to be read
 * @retval Returns a pointer to the next line from the file pointed by 'fd'
 */
char	*get_next_line(int fd);







/* ****************** FT_PRINTF ****************** */

/**
 * @brief  Mimics printf function
 * @note Helper function to solve printf conversions
 * @param  format: String to be passed as first argument
 * @retval Returns total number of printed characters
 */
int		ft_printf(const char	*format, ...);

/**
 * @brief  Prints a character to the standard output
 * @note   Helper function to solve printf conversions
 * @param  c: Character to be printed
 * @retval Returns total number of printed characters
 */
int		ft_print_char(char c);

/**
 * @brief  Prints the conversion from 'num' to the hexadecimal 
 * value of it to the standard output
 * @note   Helper function to solve printf conversions
 * @param  num: Number to be printed
 * @param  c: Character to choose from uppercase or lowercase ('x' or 'X')
 * @retval Returns total number of printed characters
 */
int		ft_print_hex(unsigned int num, const char c);

/**
 * @brief  Prints a number to the standard output
 * @note   Helper function to solve printf conversions
 * @param  num: Number to be printed
 * @retval Returns total number of printed characters
 */
int		ft_print_nbr(int num);

/**
 * @brief  Prints a pointer address to the standard output
 * @note   Helper function to solve printf conversions
 * @param  ptr: Pointer address to be printed
 * @retval Returns total number of printed characters
 */
int		ft_print_ptr(void *ptr);

/**
 * @brief  Prints a string to the standard output
 * @note   Helper function to solve printf conversions
 * @param  c: Pointer to string to be printed
 * @retval Returns total number of printed characters
 */
int		ft_print_str(char *c);

/**
 * @brief  Prints an unsigned value to the standard output
 * @note   Helper function to solve printf conversions
 * @param  num: Number to be printed
 * @retval Returns total number of printed characters
 */
int		ft_print_unsigned(unsigned int num);

#endif
