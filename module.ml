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
module SBtree (X : BTREE) = 
  struct 
    let post_visit tree = 
        let rec post_visit_node n = 
          let node_list = X.get_sons n in
          List.iter post_visit_node node_list;
          Printf.printf "%s" (X.get_label n)
        in
        post_visit_node (X.get_root tree)
  end ;;