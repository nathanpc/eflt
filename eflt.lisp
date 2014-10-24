;;; eflt Playground.
;;; == Everything here will be organized inside a library. ==
;;; Nathan Campos <nathanpc@dreamintech.net>

;; Calculates the impedance of a capacitor at a determined frequency.
(defun capacitor (c freq)
  (/ 1 (* 2 pi c freq)))

;; Dynamic function for capacitor impedance.
(defun c (uf)
  #'(lambda (freq)
	  (capacitor (* uf (expt 10 -6)) freq)))

;; Dynamic function for resistor impedance.
(defun r (r)
  #'(lambda (freq) r))

;; Dynamic function to calculate the parallel resistance.
(defun parallel (components)
  #'(lambda (freq)
	  (let ((total 0))
		(map nil #'(lambda (cmp)
					 (setf total (+ total (/ 1 (funcall cmp freq)))))
			 components)
		(/ 1 total))))

;; Dynamic function to calculate the series resistance.
(defun series (components)
  #'(lambda (freq)
	  (let ((total 0))
		(map nil #'(lambda (cmp)
					 (setf total (+ total (funcall cmp freq))))
			 components)
		total)))

;; Simulates a voltage divider.
(defun divider (freq r1 r2)
  (/ (funcall r2 freq)
	 (+ (funcall r1 freq) (funcall r2 freq))))

; Testing.
(divider 1000 (r 1000) (c 1))
