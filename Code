;;; hacktober-theme.el

(deftheme hacktober)

(let ((hacktober-fg "#c9c9c9")
      (hacktober-bg "#141414")
      (hacktober-fg-hl "#141414")
      (hacktober-bg-hl "#c9c9c9")
      (hacktober-cr "#c9c9c9")
      (hacktober-bd "#c9c9c9")
      (hacktober-black "#191918")
      (hacktober-black-bright "#2c2b2a")
      (hacktober-red "#b34538")
      (hacktober-red-bright "#b33323")
      (hacktober-green "#587744")
      (hacktober-green-bright "#42824a")
      (hacktober-yellow "#d08949")
      (hacktober-yellow-bright "#c75a22")
      (hacktober-blue "#206ec5")
      (hacktober-blue-bright "#5389c5")
      (hacktober-magenta "#864651")
      (hacktober-magenta-bright "#e795a5")
      (hacktober-cyan "#ac9166")
      (hacktober-cyan-bright "#ebc587")
      (hacktober-white "#f1eee7")
      (hacktober-white-bright "#ffffff")
      (hacktober-grey "#ccc")
      (hacktober-grey-1 "#bbb")
      (hacktober-grey-2 "#888")
      (hacktober-grey-3 "#444"))
  (custom-theme-set-faces
   'hacktober
   ;; from ITerm2 theme
   `(default ((t (:background ,hacktober-bg :foreground ,hacktober-fg))))
   `(highlight ((t (:background ,hacktober-bg-hl :foreground ,hacktober-fg-hl))))
   `(region ((t (:background ,hacktober-bg-hl :foreground ,hacktober-fg-hl))))
   `(header-line ((t (:foregound ,hacktober-yellow
                                 :box (:line-width -1 :style released-button)))))
   `(menu ((t (:foreground ,hacktober-fg :background ,hacktober-bg))))
   `(mode-line ((t (:foreground ,hacktober-green :background ,hacktober-bg
                                :box (:line-width -1 :style pressed-button)))))
   `(mode-line-inactive ((t (:foreground ,hacktober-grey-2 :background ,hacktober-bg
                                         :box (:line-width -1 :style released-button)))))
   `(mode-line-buffer-id ((t (:foreground ,hacktober-magenta :weight bold))))
   `(minibuffer-prompt ((t (:foreground ,hacktober-yellow))))
   ;; `(font-lock-comment-face ((t (:foreground ,hacktober-grey-2))))
   `(font-lock-comment-delimiter-face ((t (:foreground ,hacktober-grey-3))))
   `(font-lock-constant-face ((t (:foreground ,hacktober-cyan))))
   `(font-lock-builtin-face ((t (:foreground ,hacktober-cyan))))
   ;; `(font-lock-function-name-face ((t (:foreground ,hacktober-blue))))
   `(font-lock-variable-name-face ((t (:foreground ,hacktober-red))))
   `(font-lock-keyword-face ((t (:foreground ,hacktober-yellow))))
   `(font-lock-string-face ((t (:foreground ,hacktober-yellow-bright))))
   `(font-lock-doc-string-face ((t (:foreground ,hacktober-fg-hl))))
   `(font-lock-type-face ((t (:foreground ,hacktober-green-bright))))

   ;; from feng-shui
   '(bold ((t (:bold t :weight bold))))
   '(bold-italic ((t (:italic t :bold t :weight bold))))
   '(italic ((t (:italic t))))
   '(menu ((t (nil))))
   '(variable-pitch ((t (:family "helv"))))
   '(fixed-pitch ((t (:family "courier"))))
   `(font-lock-comment-face ((t (:italic t :foreground ,hacktober-grey-2))))
   `(font-lock-function-name-face ((t (:bold t :underline t :foreground ,hacktober-blue))))
   ))

;;;###autoload
(when load-file-name
  (add-to-list 'custom-theme-load-path
               (file-name-as-directory (file-name-directory load-file-name))))

(provide-theme 'hacktober)
