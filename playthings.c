/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playthings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 08:44:26 by znazam            #+#    #+#             */
/*   Updated: 2019/07/26 08:44:29 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void draw_box(t_env *env, t_pixel a, t_pixel b)
// {
//     int x;
//     int y;

//     if (a.x > b.x)
//     {
//         int temp = a.x;
//         a.x = b.x;
//         b.x = temp;
//     }
//     if (a.y > b.y)
//     {
//         int temp = a.y;
//         a.y = b.y;
//         b.y = temp;
//     }
//     y = a.y;
//     while (y < b.y)
//     {
//         x = a.x;
//         while (x < b.x)
//         {
//             pixel_put_image(img, 0x000000, x, y);
//             x++;
//         }
//         y++;
//     }
// }