;;; eflt.scm
;;; An electronic filter designer helper.
;;;
;;; Nathan Campos <nathan@innoveworkshop.com>

;; Pi constant.
(define pi 3.14159)

;; Converts a value to a micro unit.
(define (micro val)
  (* val (expt 10 -6)))

;; Calculates the impedance of a capacitor at a determined frequency.
(define (capacitor val freq)
  (/ 1 (* 2 pi val freq)))

;; Creates a function of the impedance of a resistor at a determined frequency.
(define (c val)
  (lambda (freq) (capacitor val freq)))

;; Creates a function of the impedance of a resistor at a determined frequency.
(define (r val)
  (lambda (freq) val))

;; Creates a function to calculate the parallel impedance.
(define (parallel components)
  ; TODO: Error if components not list.
  (lambda (freq)
	(/ 1 (apply + (map (lambda (cmp) (/ 1 (cmp freq))) components)))))

;; Creates a function to calculate the series impedance.
(define (series components)
  ; TODO: Error if components not list.
  (lambda (freq)
	(apply + (map (lambda (cmp) (cmp freq)) components))))

;; Simulates a voltage divider.
(define (divider freq r1 r2)
  (/ (r2 freq) (+ (r1 freq) (r2 freq))))
