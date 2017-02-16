<?php
include "php/banco_conexao.php";

$nome = $_POST['nome'];

$nota = $_POST['nota'];

$resultado = mysqli_query($conexao, "INSERT INTO usuarios(nome,nota) VALUES ('".$nome."',".$nota.")") or die("Não foi possível excutar a SQL:".mysqli_error($conexao));

if($resultado == TRUE){
    echo "<br/>Usuário inserido com sucesso!";
    echo "<br/><a href='index.html'>Voltar</a>";
}else{
    echo "<br/>Erro na inserção!";
    echo "<br/><a href='index.html'>Voltar</a";
}
mysqli_close($conexao);
?>