#lang racket

(require 2htdp/image)

(define WIDTH 100)
(define HEIGHT 200)

(unless (> HEIGHT 0)
  (error 'foobar "HEIGHT must not be negative"))
  
(define SQR-COLOR "red")
(define SQR-SIZE 10)
(define (draw-square img x y)
  (place-image (square SQR-SIZE "solid" SQR-COLOR)
               x y
               img))

