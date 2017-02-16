<?php
include "php/banco_conexao.php";
$nome = $_POST['nome'];
$idAluno = $_POST['idAluno'];
$nota = $_POST['nota'];

$resultado = mysqli_query($conexao, "UPDATE usuarios SET nome='".$nome."', nota=".$nota." WHERE idAluno=".$idAluno ) or die("Não foi possível executar a SQL:".mysqli_error($conexao));

if($resultado == TRUE){
    echo "<br/>Usuário atualizado com sucesso!";
    echo "<br/><a href='index.html'>Voltar</a>";
}else{
    echo "<br/>Erro na atualização!";
    echo "<br/><a href='index.html'>Voltar</a";
}

mysqli_close($conexao);
?>