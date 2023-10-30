(*
_______________________________________
EXERCICE 3 DM PROGRAMMATION ENS L3 INFO
ABEL VERLEY
_______________________________________
*)

(* Question A *)
module type BTREE = 
  sig 
    type btree
    type node
    val is_empty : btree -> bool
    val get_root : btree -> node
    val get_sons : node -> node list 
    val get_label : node -> string
  end ;;

  (* Question B *)
